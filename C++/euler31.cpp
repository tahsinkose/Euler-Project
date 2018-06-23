#include <iostream> 
int Coins[8] ={1,2,5,10,20,50,100,200}; 
#define VALUE 100000
const long mod = 1e9 + 7;

using namespace std;
int main(){
	int dp[9][VALUE+1];
	for(int i=1;i<9;i++)
		dp[i][0] = 1;
	for(int i=0;i<=VALUE;i++)
		dp[0][i] = 0;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=VALUE;j++){
			if(Coins[i-1]>j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = (dp[i-1][j] + dp[i][j-Coins[i-1]])%mod;
		}
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cout<<dp[8][n]<<endl;
	}	
	return 0;
}
