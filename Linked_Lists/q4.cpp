#include <iostream>
using namespace std;

class list
{
	public:
	int data;
	list* next;
};


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

void removeDuplicates(list **head)
{
	if(*head!=NULL)
	{
		list* current=*head;
		while(current !=NULL)
		{
			list *runner=current,*temp;
			while(runner->next!=NULL)
			{
				if(runner->next->data==current->data)
				{
					temp = runner->next;
					runner->next=runner->next->next;
					delete(temp);
				}
				else
				{
					runner = runner->next;
				}
			}
			current=current->next;
		}
	}
}

int main()
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
	insertAtFront(&a,1);
	insertAtFront(&a,2);
	insertAtFront(&a,3);
	insertAtFront(&a,4);
	insertAtFront(&a,5);
	insertAtFront(&a,6);
	insertAtMiddle(&a,9);
	printList(a);
	removeDuplicates(&a);
	printList(a);
return 0;
}


