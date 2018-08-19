#!/usr/bin/env python3
# -*- coding: utf-8

import sys
import subprocess


def main():
    exe_name = sys.argv[1]
    subprocess.call(['gcc', '-Wno-implicit-function-declaration', exe_name + '.c', '-o', exe_name, '-lm'])


if __name__ == '__main__':
    main()
