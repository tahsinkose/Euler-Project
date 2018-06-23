#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m;
        int n;
        cin>>m>>n;
        vector<vector<unsigned long long int> > grid(m+1,vector<unsigned long long int>(n+1));
        grid[m][n] = 1;//Ending node
        for(int a=m;a>=0;a--){
            for(int b=n;b>=0;b--){
                if(a+1<m+1)
                    grid[a][b]+=grid[a+1][b];
                grid[a][b]%=1000000007;
                if(b+1<n+1)
                    grid[a][b]+=grid[a][b+1];
                grid[a][b]%=1000000007;
            }
        }
        cout<<grid[0][0]%1000000007<<endl;
    }
    return 0;
}