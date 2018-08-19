#!/usr/bin/env python3
# -*- coding: utf-8

"""Checkpoints 5

This function has the following characteristics:

    - Weights on positive and negative test cases
    - Static function
    - Different weights on the functions
"""


import sys
sys.dont_write_bytecode = True

import os
import subprocess
import re
import glob
from timeit import default_timer as timer
import math
import filecmp
import random
import xxhash
import signal
import time


# ------------------------------------------------------------------------------
#   Utils
# ------------------------------------------------------------------------------


def get_test_env():
    """ Return the variables received by GenProg """

    test_name = sys.argv[1]
    exe = sys.argv[2]
    single_fitness_filename = sys.argv[3]

    if test_name == "s":
        exe = exe.replace("coverage", "repair.sanity")

    return test_name, exe, single_fitness_filename


# ------------------------------------------------------------------------------


def log(message):
    with open('/tmp/chklog', mode='a') as f:
        f.write(str(message) + "\n")


# ------------------------------------------------------------------------------


def get_script_path():
    return os.path.abspath(os.path.dirname(sys.argv[0]))


# ------------------------------------------------------------------------------


def xhash(content):
    return xxhash.xxh32(bytes(str(content), 'utf8')).intdigest()


# ------------------------------------------------------------------------------


def move_trace_file(test_name):
    path_hash = xhash(os.getcwd())

    trace_files = glob.glob('/dev/shm/' + str(path_hash) + ':*')

    for trace_file in trace_files:
        new_name = '/dev/shm/sanity:' + test_name + \
            ':' + os.path.basename(trace_file)
        os.rename(trace_file, new_name)


# ------------------------------------------------------------------------------
#   Test cases
# ------------------------------------------------------------------------------


def get_test_script_filename():
    test_script = os.path.join(get_script_path(), '/test.sh')

    if not os.path.exists(test_script):
        test_script = os.path.join(os.getcwd(), 'test.sh')

    return test_script


# ------------------------------------------------------------------------------


def get_test_cases():
    """ Get test cases from file

        regex groups:
            # group 1 = positive or negative
            # group 2 = tc side (p|n)
            # group 3 = tc id number
    """

    tcs = []
    tc_re = re.compile(r"^.*(p|n)(\d+)\).*$")

    test_filename = get_test_script_filename()

    with open(test_filename) as test_file:
        for line in test_file:
            result = tc_re.search(line)

            if result:
                tc = TestCase(-1, "")

                if result.group(1) == "p":
                    tc = PositiveTestCase(result.group(1), result.group(2))
                elif result.group(1) == "n":
                    tc = NegativeTestCase(result.group(1), result.group(2))

                tcs.append(tc)

    return tcs


# ------------------------------------------------------------------------------


class TestCase(object):
    def __init__(self, side, number):
        self.side = side
        self.number = number
        self.checkpoints = {}
        self.original_checkpoints = {}
        self.passed = 0

    def __str__(self):
        return str(self.number)

    def is_positive(self):
        return self.side == "p"

    def is_negative(self):
        return self.side == "n"


# ------------------------------------------------------------------------------


class PositiveTestCase(TestCase):
    def __init__(self, side, number):
        TestCase.__init__(self, side, number)

    def __str__(self):
        return "p" + str(self.number)


# ------------------------------------------------------------------------------


class NegativeTestCase(TestCase):
    def __init__(self, side, number):
        TestCase.__init__(self, side, number)

    def __str__(self):
        return "n" + str(self.number)


# ------------------------------------------------------------------------------
#   Checkpoints Evaluation
# ------------------------------------------------------------------------------


def checkpoints_evaluation(tcs):
    result = 0.0
    path_hash = xhash(os.getcwd())

    with open('coverage.path.neg', 'r') as fault_f:
        total_stmts_in_fault = [int(line.rstrip()) for line in fault_f]

    pos_scores = []
    neg_scores = []

    for tc in tcs:
        sanity_files = glob.glob('/dev/shm/sanity:' + str(tc) + ':' +
                                 str(path_hash) + ':*')
        sanity_files = [
            sanity for sanity in sanity_files if 'tmp___' not in sanity
        ]
        max_score = max(1, len(sanity_files))
        score = 0.0
        stmts_in_fault = 0.0

        # for each stmt in a test case
        for sanity_f in sanity_files:
            filecmp.clear_cache()
            trace_f = os.path.join('/dev/shm/',
                                   ':'.join(sanity_f.split(':')[-3:]))

            if not os.path.exists(trace_f):
                continue

            files_are_equal = filecmp.cmp(sanity_f, trace_f)

            if (tc.is_positive() and files_are_equal) or \
               (tc.is_negative() and not files_are_equal):
                score += 1.0

            if not files_are_equal and \
               int(sanity_f.split(':')[-2]) in total_stmts_in_fault:
                stmts_in_fault += 1.0

        if tc.is_positive():
            tc_score = max(score / float(max_score), tc.passed)
            pos_scores.append(tc_score)
        else:
            if score != max_score:
                wr = 0.3999999 * (stmts_in_fault / len(total_stmts_in_fault))
                tc_score = max(0.5 + wr, tc.passed)
            else:
                tc_score = tc.passed

            neg_scores.append(tc_score)

    # result
    pos_scores_len = float(len(pos_scores))
    neg_scores_len = float(len(neg_scores))

    # if pos_scores_len:
    #    result += 0.5 * (sum(pos_scores) / pos_scores_len)

    # if neg_scores_len:
    #    result += 0.5 * (sum(neg_scores) / neg_scores_len)

    result += sum(pos_scores) + sum(neg_scores)
    result /= pos_scores_len + neg_scores_len

    return result


def clear_trace_files():
    path_hash = xhash(os.getcwd())

    trace_files = glob.glob('/dev/shm/' + str(path_hash) + ':*')

    for trace_f in trace_files:
        os.remove(trace_f)


# ------------------------------------------------------------------------------
#   Black Box Evaluation (with dynamic timeout)
# ------------------------------------------------------------------------------


def get_timeout():
    path_hash = xhash(os.getcwd())
    timeout_file = os.path.join('/dev/shm', 'timeout:' + str(path_hash))
    timeout = 0.0

    if os.path.exists(timeout_file):
        with open(timeout_file, 'r') as timeout_f:
            line = timeout_f.readline()
            if line != '':
                timeout = float(line)

    return timeout


def set_timeout(timeout):
    path_hash = xhash(os.getcwd())
    timeout_file = os.path.join('/dev/shm', 'timeout:' + str(path_hash))
    old_timeout = get_timeout()
    new_timeout = math.ceil(timeout) * 1.5

    if new_timeout > old_timeout:
        with open(timeout_file, 'w') as timeout_f:
            timeout_f.write(str(new_timeout))


def run_command_with_timeout(cmd, timeout_sec):
    timeout_sec = math.ceil(timeout_sec)
    # proc = subprocess.Popen(['timeout', str(timeout_sec)] + cmd,
    #                         stdout=subprocess.PIPE,
    #                         shell=True, preexec_fn=os.setsid)
    proc = subprocess.Popen(['timeout', str(timeout_sec)] + cmd,
                            preexec_fn=os.setsid)

    benchmark_name = cmd[1]
    if 'wireshark' in benchmark_name:
        size_limit = 704532 * 1.3
    elif 'php' in benchmark_name:
        size_limit = 523000 * 1.3
    else:
        size_limit = 350000

    while proc.poll() is None:
        size = subprocess.check_output("du -s", shell=True)
        try:
            size = int(size.decode("utf-8").split('\t')[0])
        except:
            size = 0

        if size >= size_limit:
            # Send the signal to all the process groups
            os.killpg(os.getpgid(proc.pid), signal.SIGTERM)

            cwd = os.getcwd()

            if 'many-bugs' in cwd:
                benchmark = (cwd.split('/')[-1]).split('-')[0]

                os.chdir(benchmark + '/test')
                subprocess.check_output("make clean")
                os.chdir(cwd)

        time.sleep(0.5)

    proc.communicate()

    if proc.returncode != 0:
        msg = 'Process #%d killed after %f seconds' % (proc.pid, timeout_sec)
        raise subprocess.SubprocessError(msg)

    return proc.returncode


def black_box(test_name, exe=".", is_sanity=False):
    """
        Perform the (generic) black box test and return its return code
        (used by sanity and coverage, mostly)
    """

    test_script_filename = get_test_script_filename()
    command_line = ["/bin/bash", test_script_filename, str(test_name), exe]
    ret_code = -1

    # with open('/dev/shm/log', mode='a') as log_file:
    #    log_file.write(exe)
    #    log_file.write('\n')

    try:
        if is_sanity and 'coverage' not in exe:
            start = timer()
            ret_code = run_command_with_timeout(command_line, 100000)
            end = timer()

            set_timeout(end - start)
        else:
            timeout = get_timeout()

            if 'coverage' not in exe:
                ret_code = run_command_with_timeout(command_line, timeout)
            else:
                if test_name[0] == 'p':
                    ret_code = run_command_with_timeout(command_line, 100000)
                else:
                    ret_code = run_command_with_timeout(command_line,
                                                        timeout * 3)
    except subprocess.CalledProcessError:
        ret_code = -1
    except subprocess.SubprocessError:
        ret_code = -1
    except OSError:
        ret_code = -1

    return ret_code


# ------------------------------------------------------------------------------


def black_box_evaluation(tcs, exe, pos_tcs, pos_tcs_subset, neg_tcs):
    """Single Fitness: Black Box Evaluation"""

    black_box_score = 0
    black_box_maximized_sample = False

    for tc in pos_tcs_subset:
        ret_code = black_box(tc, exe)
        tc.passed = int(not bool(ret_code))
        black_box_score += 1 if ret_code == 0 else 0

    if black_box_score == len(pos_tcs_subset):
        remaining_pos_tcs = [x for x in pos_tcs if x not in pos_tcs_subset]
        black_box_maximized_sample = True

        for tc in remaining_pos_tcs:
            ret_code = black_box(tc, exe)
            tc.passed = int(not bool(ret_code))
            black_box_score += 1 if ret_code == 0 else 0

    for tc in neg_tcs:
        ret_code = black_box(tc, exe)
        tc.passed = int(not bool(ret_code))
        black_box_score += 5 if ret_code == 0 else 0

    return black_box_score, black_box_maximized_sample


# ------------------------------------------------------------------------------
#   Static Evaluation
# ------------------------------------------------------------------------------


def histogram(lst):
    hist = {}

    for element in lst:
        if element in hist:
            hist[element] += 1
        else:
            hist[element] = 1

    return hist


# Esperança E(x)
def moment(x, weight):
    # 21 = 1 + 2 + 3 + 4 + 5 + 6
    return sum([i * (x[i] / weight) for i in x]) / float(sum(x))


def file_score(output):
    output = str(output, 'utf-8')
    pattern_errors = re.compile(r':\s+\[(\d+)\]')
    errors = pattern_errors.findall(output)
    score = 1.0

    pattern_lines_analyzed = re.compile(r'Lines analyzed = (\d+)')
    lines_analyzed = pattern_lines_analyzed.findall(output)

    if lines_analyzed:
        lines_analyzed = int(lines_analyzed[0])

    if errors:
        errors = [int(x) + 1 for x in errors]
        moment_score = moment(histogram(errors), lines_analyzed)

        if moment_score:
            if 0 < moment_score <= 1:
                score = 1 - float(moment_score)
            else:
                score = 1.0 / float(moment_score)

    return score


def static_evaluation(filenames):
    scores = []
    cppcheck_score = 0

    with open('/tmp/blabla.txt', 'w') as txt_f:
        txt_f.write(str(filenames))

    # Manybugs
    if "many-bugs" in filenames:
        scenario = (filenames.split('/')[4]).split('-')[0]

        output = subprocess.check_output(['flawfinder', '-QS', scenario])
        output_cppcheck = subprocess.check_output([
                'cppcheck',
                '--xml', '--enable=all', '--quiet',
                scenario
            ], stderr=subprocess.STDOUT)

        cppcheck_score += len(output_cppcheck.decode('utf-8').split('\n'))
        scores.append(file_score(output))

    else:
        if not isinstance(filenames, list):
            filenames = filenames.split(' ')

        filenames = [x + '.c' for x in filenames]

        for filename in filenames:
            output = subprocess.check_output(['flawfinder', '-QS', filename])
            output_cppcheck = subprocess.check_output([
                'cppcheck',
                '--xml', '--enable=all', '--quiet',
                filename
            ], stderr=subprocess.STDOUT)

            cppcheck_score += len(output_cppcheck.decode('utf-8').split('\n'))

            scores.append(file_score(output))

    final_score = 0.0

    if "many-bugs" in filenames:
        if filenames:
            final_score += sum(scores) / float(len(filenames))
    else:
        final_score += sum(scores)

    if cppcheck_score:
        final_score += 1.0 / float(cppcheck_score)

    return final_score


# ------------------------------------------------------------------------------
#   Main
# ------------------------------------------------------------------------------


def random_sample(lst, k):
    return random.sample(lst, k)


def main():
    """Start point"""
    seed = 0

    if os.path.isfile('seed.txt'):
        with open('seed.txt', 'r') as seed_f:
            seed = int(seed_f.readline())

    random.seed(seed)
    test_name, exe, single_fitness_filename = get_test_env()

    if test_name[0] == "p" or test_name[0] == "n":
        ret_code = black_box(test_name, exe, True)
        move_trace_file(test_name)
        sys.exit(ret_code)


    elif test_name == "s":
        tcs = get_test_cases()
        pos_tcs = [tc for tc in tcs if tc.is_positive()]
        pos_tcs_subset = random_sample(pos_tcs, math.ceil(0.4 * len(pos_tcs)))
        neg_tcs = [tc for tc in tcs if tc.is_negative()]

        clear_trace_files()


        # ----------------------------------------------------------------------
        # Black-box evaluation
        # ----------------------------------------------------------------------

        black_box_score, black_box_maximized_sample = black_box_evaluation(tcs, exe, pos_tcs, pos_tcs_subset, neg_tcs)
        black_box_max_score = float(len(pos_tcs) + (5.0 * len(neg_tcs)))
        black_box_score_normalized = black_box_score / black_box_max_score


        # ----------------------------------------------------------------------
        # Checkpoint evaluation
        # ----------------------------------------------------------------------

        if black_box_maximized_sample:
            checkpoints_score = checkpoints_evaluation(tcs)
        else:
            checkpoints_score = checkpoints_evaluation(pos_tcs_subset + neg_tcs)


        # ----------------------------------------------------------------------
        # Static evaluation
        # ----------------------------------------------------------------------

        # static_score = static_evaluation(exe)

        # ----------------------------------------------------------------------
        # Result
        # ----------------------------------------------------------------------

        result = (0.3 * checkpoints_score) + (0.7 * black_box_score_normalized)


        # ----------------------------------------------------------------------
        # Write to finess file
        # ----------------------------------------------------------------------

        result = str.format("{0:.8f}", result)

        with open(single_fitness_filename, "wb") as single_fitness_file:
            single_fitness_file.write(str.encode(result))

        if int(black_box_score_normalized) == 1:
            sys.exit(0)
        else:
            sys.exit(1)


if __name__ == "__main__":
    main()
