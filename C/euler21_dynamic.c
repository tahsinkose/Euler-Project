#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ABOVE 100001
int sum_proper_divisors(int x);
bool check_amicability(int y,int x);
bool already_in_array(int a,int *arr,int c);
int main()
{

	int t;
	double diff;
	scanf("%d",&t);
    clock_t start, end;
    start = clock();
    int amicables[26];
	int i=2,counter = 0;
    for(; i < ABOVE; i++)
	{
		int result = sum_proper_divisors(i);
		if(i!= result && check_amicability(result,i))
		{
			if(!already_in_array(i,amicables,counter))
				*(amicables + counter++) = i;
			if(!already_in_array(result,amicables,counter))
				*(amicables + counter++) = result;
		}	 
	}
	//printf("Total amicable num: %d\n",counter);
	/*for(int i=0;i<counter;i++)
		printf("Amicable[%d] = %d\n",i,amicables[i]);*/
	for(int k=0;k<t;k++){
		int n;
		scanf("%d",&n);
		int whole_sum = 0;
		for(int j = 0; j<counter;j++){
			if(amicables[j]>=n)
				continue;
			else
				whole_sum += amicables[j];
		}
		printf("%d\n",whole_sum);	
	}
	end = clock();
	diff = ((double) (end - start)) / CLOCKS_PER_SEC;

	//printf("\nOperation took %f seconds\n", diff);

	return 0;
}

int sum_proper_divisors(int x){

	int sum = 0;
	for(int i = 2;i<=sqrt(x);i++)
	{
		if(x%i==0)
			if(i==(x/i))
				sum+=i;
			else
				sum+=i+(x/i);
	}
	return sum+1;
}

bool check_amicability(int y,int x){
	int sum = sum_proper_divisors(y);
	if(sum == x)
		return true;
	else
		return false;

}

bool already_in_array(int a,int arr[],int c)
{
	for(int i=0; i<=c;i++)
	{
		if(arr[i] == a)
			return true;
	}
	return false;
}

