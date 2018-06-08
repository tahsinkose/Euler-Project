#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        long long int a = (long long int)pow((n*(n+1)/2),2);
        long long int b = n*(n+1)*(2*n+1) / 6;
        cout<<a-b<<endl;
    }
    return 0;
}