#!/usr/bin/env bash

ulimit -t 10

let rc=1

case $1 in
  
    p1) $2 < tests/1.in.txt | diff tests/1.out.txt - >& /dev/null && let rc=$? ;;
  
    p2) $2 < tests/2.in.txt | diff tests/2.out.txt - >& /dev/null && let rc=$? ;;
  
    p3) $2 < tests/3.in.txt | diff tests/3.out.txt - >& /dev/null && let rc=$? ;;
  
    p4) $2 < tests/4.in.txt | diff tests/4.out.txt - >& /dev/null && let rc=$? ;;
  
    p5) $2 < tests/5.in.txt | diff tests/5.out.txt - >& /dev/null && let rc=$? ;;
  
    p6) $2 < tests/6.in.txt | diff tests/6.out.txt - >& /dev/null && let rc=$? ;;
  
    p7) $2 < tests/8.in.txt | diff tests/8.out.txt - >& /dev/null && let rc=$? ;;
  
    p8) $2 < tests/9.in.txt | diff tests/9.out.txt - >& /dev/null && let rc=$? ;;
  
    p9) $2 < tests/10.in.txt | diff tests/10.out.txt - >& /dev/null && let rc=$? ;;
  

  
    n1) $2 < tests/7.in.txt | diff tests/7.out.txt - >& /dev/null && let rc=$? ;;
  

    s) # single-valued fitness
      python3 test.py "$1" "$2" "$3" "$4" "$5"
      let rc=$? ;;
esac

exit "$rc"