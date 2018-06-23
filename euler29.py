import math
import time
def gcd(a,b):
    while b > 0:
        a, b = b, a % b
    return a
    
def lcm(a, b):
    return a * b / gcd(a, b)

def count_dups(exp, B):
    dup = 0
    overlaps = [0] * (B+1)
    for e in range(1, exp):
        step = lcm(e, exp) / exp
        end = e * B / exp
        for i in range(2*step, end+1, step):
            overlaps[i] = 1
    return sum(overlaps)


N = int(input())
start = time.time()
terms = [1] * (N+1)
for i in range(2, len(exponents)):
    if exponents[i] > 1:
        continue
    e = 2
    while i**e <= N:
        exponents[i**e] = e
        e += 1
dupes = {exp: count_dups(exp, N) for exp in exponents if exp > 1}
exponents = [exp for exp in exponents if exp > 1]
dup = 0
for exp in exponents:
    dup += dupes.get(exp)

print (N-1)*(N-1) - dup
elapsed = time.time() - start
#print "Elapsed time: ",elapsed," seconds"