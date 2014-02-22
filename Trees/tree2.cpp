#include <iostream>
#include <climits>

#define null NULL;

using namespace std;

// Utility that prints out an array on a line.
void printArray(int ints[], int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		cout<<ints[i];
	}
	cout<<endl;
}

class Tree
{
	public :
	int data;
	Tree* left;
	Tree* right;
};

Tree* newNode(int data)
{
	Tree* node = new Tree;
	node->data = data;
	node->left = null;
	node->right = null;
	return node;
}

Tree* build123()
{
	Tree* node = newNode(2);
	node->left = newNode(1);
	node->right = newNode(3);
}

Tree* insertTreeNode(Tree* node,int data)
{
	if(node==NULL)
	{
		return newNode(data);
	}
	else
	{
		if(data<node->data)
		{
			insertTreeNode(node->left , data);
		}
		else if(data>=node->data)
		{
			insertTreeNode(node->right , data);
		}
	}
	return node;
}

void printInOrder(Tree* node)
{
	if(node==NULL)
	{
		return;
	}
	printInOrder(node->left);
	cout<<node->data;
	printInOrder(node->right);
}

int size(Tree* node)
{
	if(node == NULL)
	{
		return 0;
	}
	return 1+size(node->left)+size(node->right);
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

int maxDepth(Tree* node)
{
	if(node == NULL)
	{
		return 0;
	}
	int rheight = 1+maxDepth(node->right);
	int lheight = 1+maxDepth(node->left);
	return max(rheight,lheight);
}

void printPostOrder(Tree* node)
{
	if(node==NULL)
	{
		return;
	}
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout<<node->data;
}

bool hasPathSum(Tree* node,int sum)
{
	if(node == NULL)
	{
		return (sum==0);
	}
	int tsum = sum-(node->data);
	return ((hasPathSum(node->left,tsum))||(hasPathSum(node->right,tsum)));
}

void printAllPaths(Tree* node)
{
	
}

void printAllPathsRecur(Tree* node, int path[], int pathLen)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
		path[pathLen]=node->data;
		pathLen++;
		if(node->right == NULL && node->left == NULL)
		{
			printArray(path, pathLen);
		}
		else
		{
			printAllPathsRecur(node->left , path ,pathLen);
			printAllPathsRecur(node->right , path ,pathLen);
		}
	}
}

void mirror(Tree* node)
{
	if(node!=NULL)
	{
		Tree* temp = new Tree;
		mirror(node->left);
		mirror(node->right);
		temp = node->right;
		node->right = node->left;
		node->left = temp;
	}
	return;
}

/*
For the key values 1...numKeys, how many structurally unique
binary search trees are possible that store those keys.
*/
int countKeys(int numKeys)
{
	if(numKeys<=1)
	{
		return 1;
	}
	else
	{
		int sum=0,left,right,root;
		for(root=1;root<=numKeys;root++)
		{
			left = countKeys(root-1);
			right = countKeys(numKeys-root);
			sum+=(left*right);
		}
		return sum;
	}
}

Tree* removeOutsideRange(Tree* node,int minVal,int maxVal)
{
	if(node == NULL)
	{
		return NULL;
	}
	else
	{
		node->left=removeOutsideRange(node->left,minVal, maxVal);
		node->right=removeOutsideRange(node->right,minVal, maxVal);
		if(node->data < minVal)
		{
			Tree* rightChild = new Tree;
			rightChild = node->right;
			delete node;
			return rightChild;
		}
		else if(node->data > maxVal)
		{
			Tree* leftChild = new Tree;
			leftChild = node->left;
			delete node;
			return leftChild;
		}
		else
		{
			return node;
		}
	}
}

Tree* pruneUtil(Tree* node,int k,int* sum)
{
	if(node==NULL)
	{
		return NULL;
	}
	int lsum = *sum+node->data;
	int rsum = lsum;
	//modify the left and right subtrees
	node->left = pruneUtil(node,k,&lsum);
	node->right = pruneUtil(node,k,&lsum);
	*sum = max(lsum,rsum);
	if(*sum<k)
	{
		delete node;
		node = NULL;
	}
	return node;
}

Tree* prune(Tree* node,int k)
{
	int sum=0;
	return pruneUtil(node,k,&sum);
}

Tree* doubleTree(Tree* node)
{
	if(node==NULL) return NULL;
	else
	{
		node->left = doubleTree(node->left);
		node->right = doubleTree(node->right);
		Tree* temp = new Tree;
		temp = node->left;
		node->left = newNode(node->data);
		node->left->left = temp;
		return node;
	}
}

int diameter(Tree* root,int* height)
{
	/* lh --> Height of left subtree
	rh --> Height of right subtree */
	int lh = 0, rh = 0;
	/* ldiameter  --> diameter of left subtree
	rdiameter  --> Diameter of right subtree */
	int ldiameter = 0, rdiameter = 0;
	if(root == NULL)
	{
		*height = 0;
		return 0; /* diameter is also 0 */
	}
	/* Get the heights of left and right subtrees in lh and rh
	And store the returned values in ldiameter and ldiameter */
	ldiameter = diameter(root->left, &lh);
	rdiameter = diameter(root->right, &rh);
	/* Height of current node is max of heights of left and
	right subtrees plus 1*/
	*height = max(lh, rh) + 1;
	return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main()
{
	Tree* t1=null;
}
