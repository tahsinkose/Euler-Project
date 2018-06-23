
n = int(input())
nums = [0]*n
for i in range(0,n):
	nums[i] = int(input())
total=0
for i in range(n):
	total+=nums[i]
total = str(total)	
print ("%s" % (total[0:10]))


