import time

def isPrime(n):
	if n==2 or n==3: return True
	if n%2==0 or n<2: return False
	for i in range(3,int(n**0.5)+1,2):
		if n%i==0:
			return False
	return True

def PrimeRange(start, stop):
    dct = {x: True for x in list(range(start, stop+1))}
    x = start

    while x ** 2 <= stop:
        if dct[x]:
            y = x ** 2
            while y <= stop:
                dct[y] = False
                y += x
        x += 1

    lst = []
    for x, y in dct.items():
        if y:
            lst.append(x)

    return lst



if __name__ == '__main__':
	start = time.time()
	n = int(input())
	primes = PrimeRange(2,n)
	maxN = 0
	maxA = None
	maxB = None
	for a in xrange(-n,n+1):
		for b in primes:
			if b <= -(1600 + 40*a):
				continue
			else:
				n = 0
				while(True):
					if a<0 and b>-(n**2 + (a*n)):
						if isPrime(n**2 + (a*n) + b):
							n+=1
						else:
							if n>maxN:
								maxN = n
								maxA = a
								maxB = b
							break
					elif a>0:
							
						if isPrime(n**2 + (a*n) + b):
							n+=1
						else:
							if n>maxN:
								maxN = n
								maxA = a
								maxB = b
							break
					else:
						break	
			

	elapsed = time.time() - start
	print maxA,maxB