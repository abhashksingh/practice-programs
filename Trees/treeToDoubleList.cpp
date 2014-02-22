#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class node
{
	public :
	int data;
	node* small;//it will play the role of previous
	node* large;//it will paly the role of next
};

/*
helper function -- given two list nodes, join them
together so the second immediately follow the first.
Sets the .next of the first and the .previous of the second.
*/
void join(node* a, node* b)
{
	a->large = b;
	b->small = a;
}

/*
helper function -- given two circular doubly linked
lists, append them and return the new list.
*/
static node* append(node* a, node* b)
{
	node* aLast;
	node* bLast;
	if (a==NULL) return(b);
	if (b==NULL) return(a);
	aLast = a->small;
	bLast = b->small;
	join(aLast, b);
	join(bLast, a);
	return(a);
}

/*
--Recursion--
Given an ordered binary tree, recursively change it into
a circular doubly linked list which is returned.
*/
static node* treeToList(node* root)
{
	node *aList, *bList;
	if (root==NULL) return(NULL);
	/* recursively solve subtrees -- leap of faith! */
	aList = treeToList(root->small);
	bList = treeToList(root->large);
	/* Make a length-1 list ouf of the root */
	root->small = root;
	root->large = root;
	/* Append everything together in sorted order */
	aList = append(aList, root);
	aList = append(aList, bList);
	return(aList);
}

/* Create a new node */
static node* newNode(int data)
{
	node* Node = new node;
	Node->data = data;
	Node->small = NULL;
	Node->large = NULL;
	return(Node);
}

/* Add a new node into a tree */
static void treeInsert(node** rootRef, int data)
{
	node *root = *rootRef;
	if (root == NULL) *rootRef = newNode(data);
	else
	{
		if (data <= root->data) treeInsert(&(root->small), data);
		else treeInsert(&(root->large), data);
	}
}

static void printList(node* head)
{
	node* current = head;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->large;
		if (current == head) break;
	}
	printf("\n");
}

/* Demo that the code works */
int main()
{
	node* root = NULL;
	node* head;
	treeInsert(&root,4);
	treeInsert(&root,2);
	treeInsert(&root,1);
	treeInsert(&root,3);
	treeInsert(&root,5);
	head = treeToList(root);
	printList(head);
	/* prints: 1 2 3 4 5
	*/
	return(0);
}
