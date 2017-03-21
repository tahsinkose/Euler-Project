#include <stdio.h>
#include <stdbool.h>
int sum_proper_divisors(int x);
bool check_amicability(int y,int x);
bool already_in_array(int a,int arr[],int c);
int main()
{
	int i=2,j;
	int amicables [20] = {0};
	int counter = 0;
	int whole_sum = 0;
	for(; i <= 10000; i++)
	{
		int result = sum_proper_divisors(i);
		if(check_amicability(result,i))
		{
			if(!already_in_array(i,amicables,counter))
				amicables[counter++] = i;
			if(!already_in_array(result,amicables,counter))
				amicables[counter++] = result;
		}	 
	}
	for(j = 0; j<counter;j++)
	{
		printf("%d\n",amicables[j]);
		whole_sum += amicables[j];
	}
	printf("total sum = %d\n",whole_sum);
	printf("amibacle number count = %d\n",counter);
}

int sum_proper_divisors(int x){

	int sum = 0,i;
	for(i = 1;i<x;i++)
	{
		if(x%i==0)
			sum+=i;
	}
	return sum;
}

bool check_amicability(int y,int x){
	int sum = sum_proper_divisors(y);
	if(sum == x && x!=y)
		return true;
	else
		return false;

}

bool already_in_array(int a,int arr[],int c)
{
	int i;
	for(i=0; i<=c;i++)
	{
		if(arr[i] == a)
			return true;
	}
	return false;
}

