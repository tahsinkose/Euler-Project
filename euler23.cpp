/*

1- check every possible pair of one number's summers for abundancy.
2- If there is no abundant ever, then accumulate it
*/
#include <iostream>
#include <cmath>
bool check_abundant_sums(int sum);
bool check_additive_abundance(int x);
int main()
{
	long long int whole_sum = 0;
	int *non_abundant_sums,*abundant_sums;
	non_abundant_sums = new int[28123];
	//abundant_sums = new int[1000];
	int counter = 0/*,abundant_counter=0*/;
	for(int a=1;a<24;a++)
		non_abundant_sums[counter++] = a;
	for(int i=24;i < 28123;i++)
	{
		std::cout<<"i : "<<i<<std::endl;
		if(!check_abundant_sums(i))
			non_abundant_sums[counter++] = i;
		/*else
			abundant_sums[abundant_counter++] = i;*/
	}
	
	for(int z = 0;z<counter;z++)
		whole_sum+=non_abundant_sums[z];

	std::cout<<"result = "<<whole_sum<<std::endl;
	/*std::cout<<"abundant sums"<<std::endl;
	for(int y = 0;y<abundant_counter;y++)
		std::cout<<abundant_sums[y]<<std::endl;*/
}




bool check_abundant_sums(int sum){
	
	for(int i = 12;i<sum;i++)
	{
		for(int j = 12;j<sum;j++)
		{
			if(i+j==sum)
			{
				if(check_additive_abundance(i) && check_additive_abundance(j))
					return true;
			}
		}
	}
	return false;
}


bool check_additive_abundance(int x){
	int sum = 0;
	for(int i = 1;i<x;i++)
	{
		if(x%i==0)
			sum+=i;
	}
	if(sum>x)
		return true;
	else
		return false;

}