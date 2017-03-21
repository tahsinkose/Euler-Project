#include <stdio.h>

int main()
{
unsigned long int i=1,largest=0,largest_n;
for(;i<=1000000;i++)
{
	//printf("Term is %d\n",i);
	unsigned long int n=i;
	unsigned long int term=0;
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
			term+=1;
			/*printf("Number was even, term is %d now.\n",term);
			getchar();*/
		}
		else
		{
			n=3*n+1;
			term+=1;
			/*printf("Number was odd, term is %d now\n",term);
			getchar();*/
		}
	}
	if(term>largest)
	{
		largest=term;
		largest_n=i;
		printf("largest value is %lu\n",largest_n);
		
	}//end if
}//end for


}
