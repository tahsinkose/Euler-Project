#ifndef __EULER18__
#define __EULER18__

#include <iostream>
using namespace std;
class BinaryNode {
	public:
		int number;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const int & theNumber,BinaryNode *lt,BinaryNode *rt)
		: number(theNumber), left(lt), right(rt) {}
		int find_max_path_sum(BinaryNode* t);

};


int find_max_path_sum(BinaryNode* t)
{
	
	int root, left, right, max_path_sum;
	max_path_sum = 0;//assume all values are positive integers.
	if(t!=NULL){
		root = t->number;
		left = find_max_path_sum(t->left);
		right = find_max_path_sum(t->right);
	
	if(left>right)
		max_path_sum = left + root;
	else if(right!=0 || left!=0)
		max_path_sum = right + root;
	else if(right==0 && left==0)
		return root;
	}	
	return max_path_sum;
}

#endif
