/*Two linked lists
 *each representing a number where each node contains a single digit
 * The digits are stored in reverse order,such that the 1's digit is at the head of the list
 * Write the function that adds two numbers and returns the result as linked list
 * */

#include<iostream>
using namespace std;

class list
{
	public:
	int data;
	list* next;
};

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

void insertData(list **head,int data)
{
	if(head!=NULL)
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
}

int main()
{
	list *a,*b;
	a=new list;
	b=new list;
	a->data=2;
	a->next=NULL;
	b->data=9;
	b->next=NULL;
}
