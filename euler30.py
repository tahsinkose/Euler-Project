import numpy as np
import time

def increment(lst,ech):
	ind = ech-1
	lst[ind] += 1
	while(True):
		if lst[ind] == 10:
			lst[ind] = 0
			ind -= 1
			lst[ind] += 1
		else:
			break
	return lst


def accumulate(dig):
	satisfiers = []
	num_as_list = [0] * dig
	num_as_list[0] = 1
	while(True):
		# print(num_as_list)
		num_as_list_with_power = np.power(num_as_list,5)
		sum_term = sum(num_as_list_with_power)
		if sum_term / (10 **(dig-1)) == 0: # First place to check whether sum_term reaches to required echelons.
			num_as_list = increment(num_as_list,dig)
			continue
		
		real_number = 0
		for i in range(dig):
			real_number += (10**i) * num_as_list[dig-1-i]
		
		if sum_term == real_number:
			satisfiers.append(int(sum_term))
		
		num_as_list = increment(num_as_list,dig)

		if num_as_list[0] == 0:
			break
	return satisfiers		
		
	


if __name__ == '__main__':
	start = time.time()
	resultList = []
	for digits in range(3,10):
		max_possible = (9**5)* digits
		if max_possible / (10 **(digits-1)) == 0:
			break
		print "%d digits" %(digits)
		returnedList = accumulate(digits)
		if returnedList == None :
			continue
		resultList.extend(returnedList)
	
	result = sum(resultList)
	elapsed = time.time() - start
	print "result : %d in %s seconds"%(result,elapsed)
	print(resultList)
