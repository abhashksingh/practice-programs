#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isNumPalindrome(string inp);
bool containsMirrorDigits(string str);

int main()
{
	int t;
	cin>>t;
	cin.ignore(); // do away with '\n'
	while(t--)
	{
		string inp;
		getline(cin,inp);
		if(isNumPalindrome(inp)&&containsMirrorDigits(inp))
		{cout<<"YES"<<endl;}
		else
		{cout<<"NO"<<endl;}
	}
}

bool isNumPalindrome(string str)
{
	int length = str.length();

	for (int i = 0; i < length / 2; i++)
		if (str[i] != str[length - 1 - i])
			return false;

	return true;
}

bool containsMirrorDigits(string str)
{
	bool ret = true;
	char a1 = '1',a2='0',a3='8';
	long long len = str.length(),i=0;
	for(i=0;i<len;i++)
	{
		if(str[i]!=a1&&str[i]!=a2&&str[i]!=a3)
		{
			ret =false;
			break;
		}
	}
	return ret;
}
