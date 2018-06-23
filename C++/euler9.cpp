#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check_pythagor(int a,int b,int c){
    return (int)(pow(a,2) + pow(b,2)) == (int)pow(c,2); 
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int max = -1;
        for(int a=1;a<n/3;a++){
            int b = (n*n - 2*n*a)/(2*n-2*a);
            int c = n-a-b;
            if(check_pythagor(a,b,c) && max<a*b*c)
                max = a*b*c;
        }
        cout<<max<<endl;
    }
    return 0;
}