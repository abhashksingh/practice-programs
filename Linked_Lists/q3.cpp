#include <iostream>
using namespace std;

class list
{
	public:
	int data;
	list* next;
};

void insertAtEnd(list **head,int data);
void insertAtMiddle(list **head,int data);
void insertAtFront(list **head,int data);
int deleteAtFront(list **head);
int deleteAtLast(list **head);
int deleteAtmiddle(list **head);
int length(list **head);
void printList(list *head);

int main(int argc, char **argv)
{
	list *a;
	a=new list;
	a->data=1;
	a->next=NULL;
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtFront(&a,0);
	insertAtFront(&a,-1);
	insertAtFront(&a,-2);
	insertAtFront(&a,-3);
	insertAtFront(&a,-4);
	insertAtFront(&a,-5);
	insertAtFront(&a,-6);
	insertAtMiddle(&a,9);
	printList(a);
	cout<<deleteAtmiddle(&a)<<endl;
	printList(a);
	cout<<deleteAtFront(&a)<<endl;
	printList(a);
	cout<<deleteAtLast(&a)<<endl;
	printList(a);
return 0;
}

void insertAtEnd(list **head,int data)
{
	list *temp = new list;
	list *temp1 = new list;
	temp1->data = data;
	temp1->next = NULL;
	temp = *head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=temp1;
}

void insertAtFront(list **head,int data)//very important function
{
	list *temp=new list;
	temp->next=*head;
	temp->data=data;
	*head=temp;
}

void insertAtMiddle(list **head,int data)
{
	if((*head)!=NULL)
	{
		list *a = new list;
		a = *head;
		list *b = new list;
		int len = length(head);
		int pos = len/2;
		for(int i=0;i<pos;i++)
		{
			a = a->next;
		}
		b->data = data;
		b->next=a->next;
		a->next=b;
	}
}

void printList(list *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int length(list **head)
{
	int count=0;
	list *current= new list;
	for (current = (*head); current != NULL; current = current->next)
	{
		count++;
	}
	return count;
}

int deleteAtFront(list **head)
{
	int data;
	if(*head!=NULL)
	{
		list *current = *head;
		data=current->data;
		list *next;
		next=current->next;
		delete current;
		current=next;
		*head=current;
	}
return data;
}

int deleteAtLast(list **head)
{
	int data;
	if(*head!=NULL)
	{
		list *current = *head,*a;
		while(current->next->next != NULL)
		{
			current=current->next;
		}
		a=current->next;
		current->next=NULL;
		data=a->data;
		delete a;
	}
return data;
}

int deleteAtmiddle(list **head)
{
	int data;
	if((*head)!=NULL)
	{
		list *a,*b,*c;
		a = *head;
		int len = length(head);
		int pos = len/2;
		for(int i=0;i<pos;i++)
		{
			a = a->next;
			if(i==(pos-2))
			{
				b = a;
			}
		}
		c = a->next;
		data = a->data;
		delete(a);
		b->next=c;
	}
return data;
}
