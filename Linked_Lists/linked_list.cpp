#include<iostream>
using namespace std;

class list
{
	public:
	int data;
	list* next;
};

void printList(list *head);
void insertData(list *head,int data);
void insertAtFront(list **head,int data);
void printLength(list *head);
list* copyList(list** head);
int deleteAtFront(list **head);
void deleteList(list **head);
void reverseList(list **head);
void deleteAtmiddle(list **head);

int main()
{
	list *a,*b,*c;
	a=new list;
	b=new list;
	c=new list;
	a->data=1;
	b->data=2;
	c->data=3;
	a->next=b;
	b->next=c;
	c->next=NULL;
	printList(a);
	cout<<endl;
	insertData(a,4);
	printList(a);
	cout<<endl;
	insertAtFront(&a,7);
	printList(a);
	cout<<endl;
	printLength(a);
	list *copy;
	//copy = new list;
	copy=copyList(&a);
	printList(copy);
	cout<<endl;
	deleteAtFront(&copy);
	printList(copy);
	cout<<endl;
	reverseList(&copy);
	printList(copy);
	cout<<endl;
}

void printList(list *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

void insertData(list *head,int data)
{
	list temp;
	temp.next=NULL;
	temp.data=data;
	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=&temp;
}

void insertAtFront(list **head,int data)//very important function
{
	list *temp=new list;
	temp->next=*head;
	temp->data=data;
	*head=temp;
}

void printLength(list *head)
{
	int count=0;
	list *current= new list;
	for (current = head; current != NULL; current = current->next)
	{
		count++;
	}
	cout<<count<<endl;
}

list* copyList(list** head)
{
	list *current=*head;
	list *newList=NULL;
	list *tail=NULL;
	while (current != NULL)
	{
		if (newList == NULL)
		{ // special case for the first new node
			newList = new list;
			newList->data = current->data;
			newList->next = NULL;
			tail = newList;
		}
		else
		{
			tail->next = new list;
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}
		current = current->next;
	}
return (newList);
}

void deleteList(list **head)
{
	list *current = *head;
	list *next;
	while(current!=NULL)
	{
		next=current->next;
		delete current;
		current=next;
	}
	*head=NULL;
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

void reverseList(list **head)
{
	list *node=NULL;
	int d;
	while(*head!=NULL)
	{
		d=deleteAtFront(head);
		insertAtFront(&node,d);
	}
	*head=node;
}
