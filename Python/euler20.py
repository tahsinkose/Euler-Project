
def factorial(n):
	product = 1
	for i in range(2,n+1):
		product *= i
	return product
if __name__=='__main__':
	t = int(input())
	for i in range(0,t):
		n = int(input())
		num = str(factorial(n))
		sum_ = 0
		for i in range(len(num)):
			sum_ += int(num[i]) -int('0')
		print sum_