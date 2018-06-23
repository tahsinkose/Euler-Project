#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
	n = int(raw_input().strip())
	n-=1
	result = 0
	t_terms = (n-3)/3 + 1
	f_terms = (n-5)/5 + 1
	ff_terms = (n-15)/15 + 1
	result += t_terms*(n+3-(n%3))/2
	
	result += f_terms*(n+5-(n%5))/2
	
	result -= ff_terms*(n+15-(n%15))/2
	print result

