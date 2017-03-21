#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int sum_proper_divisors(int x);
bool check_amicability(int y,int x);
bool already_in_array(int a,int *arr,int c);
int main()
{
	int i=2;
	
	int *amicables;
	amicables = (int *) malloc(20);	
	int counter = 0;
	int whole_sum = 0;
	for(; i <= 10000; i++)
	{
		int result = sum_proper_divisors(i);
		if(check_amicability(result,i))
		{
			if(!already_in_array(i,amicables,counter))
				*(amicables + counter++) = i;
			if(!already_in_array(result,amicables,counter))
				*(amicables + counter++) = result;
		}	 
	}
	for(int j = 0; j<counter;j++)
	{
		whole_sum += amicables[j];
	}
	printf("total sum = %d\n",whole_sum);
	printf("amibacle number count = %d\n",counter);
}

int sum_proper_divisors(int x){

	int sum = 0;
	for(int i = 1;i<x;i++)
	{
		if(x%i==0)
			sum+=i;
	}
	return sum;
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

