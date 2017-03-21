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




start = time.time()
for i in range(3,1001):
	
	if check_co_prime(i) and i%2!=0 and i%5!=0:
		"""print("{0} is co-prime to 10\n".format(i))"""
		base = 10
		k = 1
		while True:
			if (base-1) % i == 0:
				break
			base*=10
			"""print("base = {0}\n".format(base))"""
			k = k + 1
		"""print("k = {0}".format(k))
		print("cycles = {0}".format(cycles))
		raw_input()"""
		if k > cycles:
			cycles = k
			number = i
end = time.time()			
print("cycles = {0}, number = {1}\n".format(cycles,number))
print("calculated in {0} seconds\n".format(end-start))
