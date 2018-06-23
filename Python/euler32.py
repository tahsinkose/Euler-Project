def containsDuplicate(num):
	arr = parseInt(num)
	if len(arr) != len(set(arr)):
		return True
	return False

def notcontainsDup(arr):
	if len(arr) == len(set(arr)):
		return True
	return False
def excludesZero(arr):
	if 0 in arr:
		return False
	return True

def parseInt(number):
	digits=[]
	tmp = number
	i=1
	while(tmp>=10):
		f = tmp % 10
		tmp = tmp//10
		digits.append(f)
	digits.append(tmp)
	return digits


def two_by_three():
	resultList = []
	for i in xrange(10,99):
		for j in xrange(100,999):
			if i%10==0 or j%10==0:
				continue
			elif containsDuplicate(i) or containsDuplicate(j):
				continue
			else :
				product = i*j
				prodDigits = parseInt(product)
				iDigs = parseInt(i)
				jDigs = parseInt(j)
				result = prodDigits + iDigs + jDigs
				if(len(result) == 9 and excludesZero(result) and notcontainsDup(result)):
					print(result)
					print "i = %d, j = %d, prod = %d" %(i,j,product)
					resultList.append(product)
	return resultList


def one_by_four():
	resultList = []
	for i in xrange(1,10):
		for j in xrange(1000,10000):
			if j%10==0:
				continue
			elif containsDuplicate(i) or containsDuplicate(j):
				continue
			else :
				product = i*j
				prodDigits = parseInt(product)
				iDigs = parseInt(i)
				jDigs = parseInt(j)
				result = prodDigits + iDigs + jDigs
				if(len(result) == 9 and excludesZero(result) and notcontainsDup(result)):
					print(result)
					print "i = %d, j = %d, prod = %d" %(i,j,product)
					resultList.append(product)
	return resultList

if __name__ == "__main__":
	firstList = two_by_three()
	secondList = one_by_four()
	finalList = firstList + secondList
	
	finalList = list(set(finalList))
	print (sum(finalList))
	print(finalList)
						
				
	
		
