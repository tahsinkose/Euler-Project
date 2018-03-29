#include <iostream>
#include <set>
#include <string>
using namespace std;

bool isPalindrome(int x){
	string s = to_string(x);
	for(int i=0;i<3;i++){
		if(s[i]!=s[5-i])
			return false;
	}
	return true;
}
void palindromes(set<int>& s){
	for(int i=100;i<1000;i++){
		for(int j=100000/i+1;j<1000;j++){
			if(isPalindrome(i*j))
				s.insert(i*j);
		}
	}
}
int main(){
	int tests;
	cin>>tests;
	set<int> p;
	palindromes(p);
	for(int i=0;i<tests;i++){
		int N;
		cin>>N;
		set<int>::iterator it = p.lower_bound(N);
		it--;
		cout<<*it<<endl;
	}
	return 0;
}
