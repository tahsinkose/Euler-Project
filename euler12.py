import math
def num_divisors(n):
	count=0
	for i in range(1,int(math.ceil(math.sqrt(n)))):
		if n%i == 0:
			if n/i == i:
				count += 1
			else:
				count += 2
	return count

for i in range(1,41041):
	val = num_divisors(i*(i+1)/2)
	
t = int(input())
for i in range(0,t):
	n = int(input())
	init = 1
	for j in range(1,41041):
		val = j*(j+1)/2
		if num_divisors(val) > n:
			print(val)
			break
	
