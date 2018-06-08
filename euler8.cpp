#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        int max = 0;
        for(int i=0;i<num.size()-k;i++){
            int product = 1;
            for(int j=0;j<k;j++)
                product*=num[i+j]-'0';
            if(product>max)
                max = product;
        }
        cout<<max<<endl;
    }
    return 0;
}