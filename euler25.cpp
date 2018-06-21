#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print_vector(vector<char> &a)
{
	int j;
	for(j=0;j<a.size();j++)
			cout<<a[j];
	cout<<endl;
}
void sum(vector<char> & a,vector<char> & b,vector<char> & result){
	int first_size,second_size,i,k,x,y,carry=0,temp_sum;
	vector<char> revert_a, revert_b,revert_result;
	revert_a.resize(a.size());
	revert_b.resize(b.size());
	result.resize(b.size());
	revert_result.resize(b.size());
	first_size = a.size();
	for(i=0,k=first_size-1;k>=0;k--)
	{
		revert_a[i] = a[k];
		i++;
	}
	/*cout<<"revert_a"<<endl;
	print_vector(revert_a);*/
	second_size = b.size();
	for(i=0,k=second_size-1;k>=0;k--)
	{
		revert_b[i] = b[k];
		i++;
	}
	/*cout<<"revert_b"<<endl;
	print_vector(revert_b);*/
	for(i=0;i<second_size;i++)
	{
		if(i<first_size)
		{
			
			x = revert_a[i] - '0';
			y = revert_b[i] - '0';
		//	cout<<"x = "<<x<<" , y = "<<y<<" , carry = "<<carry<<endl;
			temp_sum = (x+y+carry)%10;
			revert_result[i]=temp_sum + '0';
			carry = (x+y+carry) / 10;
		}
		else
		{
			y = revert_b[i] - '0';
			temp_sum = (y+carry)%10;
			revert_result[i]=temp_sum + '0';
			carry = (y + carry) / 10;
		}
		
	}
	if(carry)
	{
		revert_result.resize(second_size+1);
		result.resize(second_size+1);
		revert_result[i]='1';
	}
	for(i=0,k=revert_result.size() - 1;k>=0;k--)
	{
		result[i] = revert_result[k];
		i++;
	}
	
}
int main()
{
	int i=2,size,j; //i is 2 because of first and second char arrays
	//vector<char *> depot;
	vector< vector<char> > depot;
	
	vector<char> first;
	first.push_back('1');
	
	vector<char> second;
	second.push_back('1');
	
	depot.push_back(first);
	depot.push_back(second);
	vector<int> unique_indices(5001,0);
	int unique_indice = 2;
	while(unique_indice<=5000)
	{
		vector<char> result;
		size = depot.size();
		sum(depot[size-2],depot[size-1],result);
		depot.push_back(result);
		i++;
		if(result.size()==unique_indice){
			unique_indices[unique_indice] = i;
			unique_indice++;
		}
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		cout<<unique_indices[n]<<endl;
	}
	
	return 0;	
}
