#!/bin/python

import sys


t = int(raw_input().strip())
k = 80
fib = [1]*k
fib[1] = 2
for i in range(2,k):
    fib[i]=fib[i-1] + fib[i-2]
for a0 in xrange(t):
    result = 0
    n = long(raw_input().strip())
    step = 1
    while step<80 and fib[step]<=n:
        result+=fib[step]
        step+=3
    print result
