import time

if __name__ == '__main__':
	
	resultList = []
	N = int(input())
	
	start = time.time()
	max_possible = (9**N)* N
	#print "max_possible: ",max_possible
	limit = 550000
	if max_possible < limit:
		limit = max_possible
	for i in range(2,limit):
		x = str(i)
		sum_ = 0
		for j in range(len(x)):
			sum_ += (int(x[j])-int('0'))**N
		if sum_ == i:
			resultList.append(i)
	elapsed = time.time() - start
	#print "elapsed in",elapsed," seconds"
	print sum(resultList)
	
