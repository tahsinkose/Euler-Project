#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int t;
    cin >> t;
    vector<bool> nums(1000001,true);
    vector<long> sums(1000001,0);
    for(int p=2;p*p<1000001;p++){
        
        if(nums[p]){
            for(int j=p*p;j<1000001;j+=p)
                nums[j] = false;
        }
    }
    for(int i=2;i<=1000000;i++){
        sums[i] += sums[i-1];
        if(nums[i])
            sums[i] += i;
    }
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<sums[n]<<endl;
    }

    return 0;
}