from num2word import to_card
total_count = 0
for i in range(1,1001):
	word = to_card(i)
	counter = 0
	for c in word:
		if(ord(c)>=97):
			counter= counter +1
	total_count = total_count + counter
	print(word + " length :{0} ".format(counter))

print("total number of letters used :{0} ".format(total_count))
