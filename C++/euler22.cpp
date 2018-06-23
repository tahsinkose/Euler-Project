#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, char * argv[])
{
  int n,q;
  cin>>n;
  vector<string> words(n);
  for(int i=0;i<n;i++)
    cin>>words[i];
  sort(words.begin(),words.end());
  
  cin>>q;
  for(int i=0;i<q;i++){
    string query;
    cin>>query;
    vector<string>::iterator it = find(words.begin(),words.end(),query);
    int place = distance(words.begin(),it);
    int result = 0;
    for(int j=0;j<query.size();j++)
      result += query[j] - 'A' + 1;
    cout<<result*(place+1)<<endl;
  }
  return 0;
}