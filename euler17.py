def cvt(c):
	if c=='1':
		return "One"
	elif c=='2':
		return "Two"
	elif c=='3':
		return "Three"
	elif c=='4':
		return "Four"
	elif c=='5':
		return "Five"
	elif c=='6':
		return "Six"
	elif c=='7':
		return "Seven"
	elif c=='8':
		return "Eight"
	elif c=='9':
		return "Nine"
def cvt_ten(b):
	if b=='0':
		return "Ten"
	elif b=='1':
		return "Eleven"
	elif b=='2':
		return "Twelve"
	elif b=='3':
		return "Thirteen"
	elif b=='4':
		return "Fourteen"
	elif b=='5':
		return "Fifteen"
	elif b=='6':
		return "Sixteen"
	elif b=='7':
		return "Seventeen"
	elif b=='8':
		return "Eighteen"
	return "Nineteen"
def cvt_not_ten(a,b):
	ret = None
	if a=='2':
		ret = "Twenty"
	elif a=='3':
		ret = "Thirty"
	elif a=='4':
		ret = "Forty"
	elif a=='5':
		ret = "Fifty"
	elif a=='6':
		ret = "Sixty"
	elif a=='7':
		ret = "Seventy"
	elif a=='8':
		ret = "Eighty"
	else:
		ret = "Ninety"
	if b!='0':
		ret += " "+cvt(b)
	return ret



def translate(n,i,suffix):
	if n[i]!='0' or n[i+1]!='0' or n[i+2]!='0':
			if n[i]!='0':
				print cvt(n[i]),"Hundred",
			if n[i+1]!='0':
				if n[i+1]=='1':
					print cvt_ten(n[i+2]),suffix,
				else:
					print cvt_not_ten(n[i+1],n[i+2]),suffix,
			else:
				print cvt(n[i+2]),suffix,

def translate_(n,i,suffix):
	if n[i]!='0' or n[i+1]!='0' or n[i+2]!='0':
			if n[i]!='0':
				print cvt(n[i]),"Hundred",
			if n[i+1]!='0':
				if n[i+1]=='1':
					print cvt_ten(n[i+2]),suffix
				else:
					print cvt_not_ten(n[i+1],n[i+2]),suffix
			else:
				if n[i+2]!='0':
					print cvt(n[i+2]),suffix

if __name__=='__main__':
	t = int(input())
	for i in range(0,t):
		n = str(input())
		n = "0"*(12 - len(n)) + n
		translate(n,0,"Billion")
		translate(n,3,"Million")
		translate(n,6,"Thousand")
		translate_(n,9,"")
		