/*Take two strings as input decide if one is the permutation of other*/
#include <iostream>
#include <string>
using namespace std;
bool isPermutation(string str1,string str2);
int main(int argc,char **argv)
{
	string str1,str2;
	cout<<"Enter first string: ";
	getline(cin,str1);
	cout<<"Enter second string: ";
	getline(cin,str2);
	bool permu=isPermutation(str1,str2);
	cout<<permu<<endl;
return 0;
}

bool isPermutation(string str1,string str2)
{
	if(str1.length()!=str2.length())
	{
		return false;
	}
	else
	{
		int chac[256];
		for(int i=0;i<256;i++)
		{
			chac[i]=0;
		}
		for(int i=0;i<str1.length();i++)
		{
			int val=str1[i];
			chac[val]++;
		}
		for(int i=0;i<str2.length();i++)
		{
			int val=str2[i];
			chac[val]--;
		}
		for(int i=0;i<256;i++)
		{
			if(chac[i]!=0)
			{
				return false;
			}
		}
	}
	return true;
}
