#include <iostream>

using namespace std;

int gcd(int x,int y){
    int less = (x<y ? x : y);
    for(int i=less;i>=1;i--)
        if(x%i==0 && y%i==0)
            return i;
    return 1;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int product = 1;
        for(int i=1;i<=n;i++)
            product *= i/gcd(product,i);
        cout<<product<<endl;
    }
    return 0;
}