// Program to print all permutations of a string in sorted order.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// Using Factorial number system, this question can be solved in O(1).
// https://en.wikipedia.org/wiki/Factorial_number_system

using namespace std;
unsigned long long int fact(int j){
	unsigned long long int result = 1;
	for(int i=2;i<=j;i++)
		result*=i;
	return result;
}
int main()
{
    string str = "abcdefghijklm";
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	unsigned long long int n;
    	cin>>n;
    	n--;
    	vector<int> factoradic;
    	int j=1;
    	while(n && j<=13){
    		factoradic.push_back(n%j);
    		n /= j;
    		j++;
    	}
    	
    	for(int k=j;k<=13;k++)
    		factoradic.push_back(0);
    	reverse(factoradic.begin(),factoradic.end());
    	string tmp = str;
    	string result;
    	for(int k=0;k<factoradic.size();k++){
    		result.push_back(tmp[factoradic[k]]);
    		tmp.erase(factoradic[k],1);
    	}
    	cout<<result<<endl;
    }
    return 0;
}
