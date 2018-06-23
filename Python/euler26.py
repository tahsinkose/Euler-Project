# https://en.wikipedia.org/wiki/Modular_exponentiation

import time

cycles = 0
number = 0

def check_co_prime(n):
	if n<10:
		limit = n
	else:
		limit = 10
	for i in range(2,limit+1):
		if n%i==0 and 10%i==0:
			return False
	return True



if __name__=='__main__':
	start = time.time()
	longest = [0]*10001
	for i in range(3,10001):
		
		if check_co_prime(i) and i%2!=0 and i%5!=0:
			base = 10
			k = 1
			while True:
				if pow(base,k,i) == 1:
					break			
				k = k + 1
			
			if k > cycles:
				cycles = k
				number = i
		longest[i] = number
	end = time.time()
	t = int(input())
	for i in range(0,t):
		n = int(input())
		print(longest[n])

