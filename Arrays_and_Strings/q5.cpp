/* Implement a function to perform basic string compression using the counts repeated
 * e.g. aabcccdddd to a2bc3d4
 * */
#include <iostream>
#include <string>
using namespace std;
bool compress(string str);
char itoa(int i);
int main()
{
	string str1;
	getline(cin,str1);
	bool suc=compress(str1);
	cout<<suc<<endl;
return 0;
}

bool compress(string str)
{
	string str1;
	int count=1,str1l=0;
	char last;
	last=str1[str1l]=str[0];
	for(unsigned int i=1;i<str.length();i++)
	{
		if(last==str[i])
		{
			count++;
		}
		else
		{
			char temp=itoa(count);
			str1l++;
			if(temp!='1')
			{
				str1[str1l]=temp;
				str1l++;
			}
			last=str[i];
			count=1;
		}
	}
	//cout<<last<<count<<endl;
	cout<<str1;
return true;
}

char itoa(int i)
{
	char t;
	switch(i)
	{
		case 1 :
			t = '1';
			break;
		case 2 :
			t ='2';
			break;
		case 3 :
			t = '3';
			break;
		case 4 :
			t = '4';
			break;
		case 5 :
			t = '5';
			break;
		case 6 :
			t = '6';
			break;
		case 7 :
			t = '7';
			break;
		case 8 :
			t = '8';
			break;
		case 9 :
			t = '9';
			break;
	}
	//cout<<t<<endl;
return t;
}
