/*Take a string as input and replace all its spaces with %20
 *e.g."Mr. John Smith" to "Mr.%20John%20Smith"
 * but "Mr. John Smith   " to "Mr.%20John%20Smith"
 * */
#include <iostream>
#include <string>
using namespace std;
void print_required(string str1);
int main()
{
	string str1;
	cout<<"Enter the string: ";
	getline(cin,str1);
	print_required(str1);
}

void print_required(string str1)
{
	int len=str1.length();
	/*First check that there are no space at the end better just trim it.I am writing the code snippet for it */
	for(int i=len-1;i>0;i--)
	{
		if(str1[i]==' ')
		{
			str1[i]='\0';
			len--;
		}
		else
		{
			break;
		}
	}
	//cout<<str1<<" "<<len;
	//now counting the number of spaces in the rest of string
	int count=0;
	for(int i=len-1;i>0;i--)
	{
		if(str1[i]==' ')
		{
			count++;
		}
	}
	char newstr[len+2*count];
	int i=0,j=0;
	while(i<len)
	{
		if(str1[i]==' ')
		{
			newstr[j]='%';
			newstr[j+1]='2';
			newstr[j+2]='0';
			j+=2;
		}
		else
		{
			newstr[j]=str1[i];
		}
		i++;j++;
	}
	newstr[len+2*count]='\0';
	cout<<newstr<<endl;
}
