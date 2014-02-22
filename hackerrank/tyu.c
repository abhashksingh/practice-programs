#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	int rightcount;
}tree;
tree *root = NULL;
int get_inv(int val)
{
	int inv = 0;
	tree *newnode = (tree*)malloc(sizeof(tree));
	newnode->value = val;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->rightcount = 0;
	if(root == NULL)
	{
		root = newnode;
		return 0;
	}
	tree *presentnode = root;
	tree *parentnode = root;
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
		parentnode->left = newnode;
	else
		parentnode->right = newnode;
	return inv;
}
int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int numtest = -1;
	scanf("%d", &numtest);
	int *result = (int*)malloc(numtest * sizeof(int));
	for(int i=0; i < numtest; i++)
	{
		int arrlen = -1;
		scanf("%d", &arrlen);
		int *arrptr = (int*)malloc(arrlen * sizeof(int));
		for(int i = 0; i<arrlen; i++)
		{
			scanf("%d", arrptr + i);
		}
		int inv = 0;
		for(int i = 0; i< arrlen;i++)
			inv += get_inv(*(arrptr + i));
		*(result + i) = inv;
		root = NULL;
	}
	for(int i =0; i<numtest;i++)
	{
		printf("%d\n", *(result+i));
	}
return 0;
}
