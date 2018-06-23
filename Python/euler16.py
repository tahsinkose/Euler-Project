import math


t = int(input())
for i in range(0,t):
	n = int(input())
	num = str(2**n)
	sum = 0
	for j in range(len(num)):
		sum+=int(num[j])-int('0')
	print(sum)