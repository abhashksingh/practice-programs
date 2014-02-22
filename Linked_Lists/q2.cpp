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
	
}
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
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	insertAtEnd(&a,2);
	insertAtEnd(&a,3);
	insertAtEnd(&a,4);
	insertAtEnd(&a,5);
	insertAtEnd(&a,6);
	insertAtEnd(&a,7);
	printList(a);
	removeDuplicates(&a);
return 0;
}
