#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class node
{
	public :
		int data;
		node* next;
};

node* publicStack = NULL;
void push(node** headref,int data);
int pop(node** headref);
bool isEmpty(node* head);
int length(node* head);
void addSameLength(node* head1,node* head2);
void printList(node* head);
void swapPointers(node** head1,node** head2);
node* addLists(node* head1,node* head2);
node* managePublicStack();

int main()
{
	publicStack=NULL;
	node* head1 =NULL;
	node* head2 =NULL;
	push(&head1,9);
	push(&head1,9);
	push(&head1,9);
	push(&head1,9);
	push(&head2,9);
	push(&head2,2);
	cout<<"First Linked List is : ";
	printList(head1);
	cout<<"Second Linked List is : ";
	printList(head2);
	node* res = addLists(head1,head2);
	cout<<"Result is : ";
	printList(res);
return 0;
}

void push(node** headref,int data)
{
	if((*headref)!=NULL)
	{
		node* temp = new node;
		temp->data = data;
		temp->next = *headref;
		*headref = temp;
	}
	else
	{
		(*headref) = new node;
		(*headref)->data = data;
		(*headref)->next = NULL;
	}
}

int pop(node** headref)
{
	if((*headref)!=NULL)
	{
		int d = (*headref)->data;
		node* temp = *headref;
		(*headref)=(*headref)->next;
		delete temp;
		return d; 
	}
	else
	{
		return INT_MIN;
	}
}

bool isEmpty(node* head)
{
	return (head==NULL);
}

int length(node* head)
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		int ret=0;
		while(head!=NULL)
		{
			ret++;
			head=head->next;
		}
		return ret;
	}
}

void printList(node* head)
{
	if(head != NULL)
	{
		while(head != NULL)
		{
			cout<<head->data;
			head=head->next;
		}
		cout<<endl;
	}
}

void addSameLength(node* head1,node* head2)
{
	if(head1!=NULL && head2!=NULL)
	{
		while(head1!=NULL && head2!=NULL)
		{
			push(&publicStack,head1->data+head2->data);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}

node* addLists(node* head1,node* head2)
{
	if(head1==NULL || head2==NULL)
	{
		return NULL;
	}
	else
	{
		node* res = new node;
		int l1 = length(head1);
		int l2 = length(head2);
		if(l1!=l2)
		{
			if(l2>l1)
			{
				swapPointers(&head1,&head2);
			}
			int dif = l1-l2;
			for(int i=0;i<dif;i++)
			{
				push(&publicStack,head1->data);
				head1 = head1->next;
			}
		}
		addSameLength(head1,head2);
		res = managePublicStack();
		return res;
	}
}

node* managePublicStack()
{
	int carry = 0;
	if(publicStack==NULL)
	{
		return NULL;
	}
	else
	{
		int t,p;
		node* res = NULL;
		t = pop(&publicStack);
		p=t%10;
		carry=t/10;
		push(&res,p);
		while(!isEmpty(publicStack))
		{
			t = pop(&publicStack);
			p=(carry+t)%10;
			carry=(carry+t)/10;
			push(&res,p);
		}
		if(carry>0)
		{
			push(&res,carry);
		}
		return res;
	}
}

void swapPointers(node** head1,node** head2)
{
	node* t = new node;
	t = *head1;
	*head1 = *head2;
	*head2 = t;
}
