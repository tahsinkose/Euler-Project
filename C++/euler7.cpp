#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int t;
    cin >> t;
    vector<long long int> primes(10000);
    primes[0] = 2;
    primes[1] = 3;
    int top = 1;
    for(long long int i=5;i<=150000;i+=2){
        for(int j=0;j<=top;j++){
            if(i%primes[j]==0)
                break;
            if(j==top){
                primes[++top] = i;
                break;
            }
        }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<primes[n-1]<<endl;
    }
    return 0;
}