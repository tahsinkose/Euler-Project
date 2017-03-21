#include <stdio.h>
long long int factorial(long long int a);
int sum_digit(long long int b);
int main()
{
	long long int x = 93326215443944152;
	long long int y = 681699238856266;
	long long int z = 70049071596826438;
	long long int w = 1621468592963895;
	long long int q = 21759999322991560;
	long long int p = 8941463976156518;
	long long int m = 28625369792082722;
	long long int n = 3758251185210916;
	printf("%d\n",sum_digit(x) + sum_digit(y) + sum_digit(z) + sum_digit(w) + sum_digit(q) + sum_digit(p) + sum_digit(m) + sum_digit(n) + 18);
	return 0;
}

long long int factorial(long long int a)
{
	if(a<1)
		return 1;
	else
		return a*factorial(a-1);
}

int sum_digit(long long int b)
{
	int result = 0;
	while(b)
	{
		result += b%10;
		b/=10;
	}
	return result;
}