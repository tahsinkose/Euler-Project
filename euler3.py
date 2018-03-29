#!/bin/python

import sys


t = int(raw_input().strip())

for a0 in xrange(t):
	result = 0	
	n = long(raw_input().strip())
    	d = 2
	largest_factor = 0
	while n > 1:
		while n%d==0:
			if largest_factor < d:
				largest_factor = d
			n /= d

		d = d + 1
		if d*d > n:
			if n>1 and largest_factor < n:
				largest_factor = n
			break
	print largest_factor
