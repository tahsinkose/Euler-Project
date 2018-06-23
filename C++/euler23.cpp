/*

1- check every possible pair of one number's summers for abundancy.
2- If there is no abundant ever, then accumulate it
*/
#include <iostream>
#include <cmath>
#include <ctime>
#define N 28124
int sum_proper_divisors(int x);

int main()
{
	
	int *proper_sums;
	proper_sums = new int[N];
	int counter = 0;
	double diff;
	clock_t start, end;
    start = clock();
	for(int i=0;i<N;i++)
		proper_sums[i] = sum_proper_divisors(i);

	end = clock();
	diff = ((double) (end - start)) / CLOCKS_PER_SEC;
	int t;
	std::cin>>t;
	for(int i=0;i<t;i++){
		int n;
		std::cin>>n;
		if(n>=28123){
			std::cout<<"YES"<<std::endl;
			continue;
		}
		bool f = false;
		for(int j=12;j<=n/2;j++){
			if(proper_sums[j]>j && proper_sums[n-j]>n-j){
				std::cout<<"YES"<<std::endl;
				f = true;
				break;
			}
		}
		if(!f)
			std::cout<<"NO"<<std::endl;
	}
	//std::cout<<"Operation took "<<diff<<" seconds"<<std::endl;
	delete proper_sums;
	
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

