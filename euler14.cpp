#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
	unsigned long int i=1,largest=0,largest_n;
	vector<pair<unsigned long int,int> > collatz;
	for(;i<=6000000;i++)
	{
		unsigned long int n=i;
		unsigned long int term=0;
		while(n!=1)
		{
			if(n%2==0)
			{
				n/=2;
				term+=1;
			}
			else
			{
				n=3*n+1;
				term+=1;
			}
		}
		
		if(term>=largest)
		{
			largest=term;
			largest_n=i;
			
			collatz.push_back({largest_n,largest});
		}//end if
	}//end for
	/*for(int i=0;i<collatz.size();i++)
		printf("Index %ld with value %d\n",collatz[i].first,collatz[i].second);
	printf("OK\n");*/
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		if(n==1){
			printf("0\n");
			continue;
		}
		for(int j=0;j<collatz.size();j++){
			if(n<collatz[j].first){
				printf("%ld\n",collatz[j-1].first);
				break;
			}
		}
	}

}
