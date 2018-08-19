#!/usr/bin/env bash

ulimit -t 10

let rc=1

case $1 in
  
    p1) $2 < tests/1.in.txt | diff tests/1.out.txt - >& /dev/null && let rc=$? ;;
  
    p2) $2 < tests/2.in.txt | diff tests/2.out.txt - >& /dev/null && let rc=$? ;;
  
    p3) $2 < tests/3.in.txt | diff tests/3.out.txt - >& /dev/null && let rc=$? ;;
  
    p4) $2 < tests/6.in.txt | diff tests/6.out.txt - >& /dev/null && let rc=$? ;;
  

  
    n1) $2 < tests/4.in.txt | diff tests/4.out.txt - >& /dev/null && let rc=$? ;;
  
    n2) $2 < tests/5.in.txt | diff tests/5.out.txt - >& /dev/null && let rc=$? ;;
  

    s) # single-valued fitness
      python3 test.py "$1" "$2" "$3" "$4" "$5"
      let rc=$? ;;
esac

exit "$rc"