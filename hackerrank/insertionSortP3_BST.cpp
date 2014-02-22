#include <vector>
#include <iostream>

using namespace std;

class Tree
{
	public:
	int value;
	int rightcount;
	Tree *left;
	Tree *right;  
	//Tree *parent;  
};
int get_inv(int val);
Tree *root=NULL;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int size,count=0;
		cin>>size;
		int *arr=new int[size];
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
			count+=get_inv(arr[i]);
		}
		cout<<count<<endl;
		root=NULL;
	}
}

int get_inv(int val)
{
	int inv = 0;
	Tree *newnode = new Tree;
	newnode->value = val;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->rightcount = 0;
	if(root == NULL)
	{
		root = newnode;
		return 0;
	}
	Tree *presentnode = root;
	Tree *parentnode = root;
	while(presentnode != NULL)
	{
		parentnode = presentnode;
		if(val < presentnode->value)
		{
			inv += presentnode->rightcount + 1;
			presentnode = presentnode->left;
		}
		else
		{
			presentnode->rightcount++;
			presentnode = presentnode->right;
		}
	}
	if(val < parentnode->value)
	{
		parentnode->left = newnode;
	}
	else
	{
		parentnode->right = newnode;
	}
	return inv;
}
