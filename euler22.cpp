#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;
bool sortfunc(char *a,char *b) { 
  string strA(a);
  string strB(b);
  if(strA.compare(strB) < 0)
    return true;
  else
    return false;
}
int word_worth(char *str)
{
  int result = 0;
  while(*str!='\0')
  {
    int tmp = (*str) - 'A' + 1;
    result+=tmp;
    cout<<*str<<" : "<<tmp<<endl;
    str++;
  }
  cout<<"result: "<<result<<endl;
  
  return result;
}
int main(int argc, char * argv[])
{
   int sum_scores = 0;
   ifstream inFile;
   inFile.open(argv[1],ios::in); 
   if (inFile.is_open())
   {
      string line;

     getline (inFile,line); //Fixing it as per the comment made by MSalters
     vector<char *> words;
     char * writable = new char[line.size() + 1];
     copy(line.begin(), line.end(), writable);
     writable[line.size()] = '\0'; // don't forget the terminating 0
     char *token;
     token = strtok(writable,",\"");

     while(token!=NULL)
     {
        //cout<<token<<endl;
        words.push_back(token);
        token=strtok(NULL,",\"");
     }
     sort(words.begin(),words.end(),sortfunc);
     //Accumulated in words.
     /*for(int i=0;i<words.size();i++)
       cout<<words[i]<<endl;*/
     for(int i=0;i<words.size();i++)
     {
        int score = word_worth(words[i]);
        score *= i+1;
        cout<<"score : "<<score<<endl;
        sum_scores += score;
     }
    cout<<sum_scores<<endl;
     inFile.close();
     delete[] writable;
   }
    
   else std::cout << "Unable to open file";

  return 0;
}