#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream> 
#include <cstring>

using namespace std;

void split(string ref,string &lh,string &rh);
bool isPermutation(string str1,string str2);

int main()
{
	char a;
	int T;
	cin>>T;
	scanf("%c",&a);
	while(T--)
	{
		string str,lh,rh;
		getline(cin,str);
		//cout<<str<<endl;
		split(str,lh,rh);
		//cout<<lh<<"   "<<rh<<endl;
		if(isPermutation(lh,rh))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

void split(string ref,string &lh,string &rh)
{
	int len=ref.length(),i=0;
	for(i=0;i<(len/2);i++)
	{
		lh.push_back(ref[i]);
	}
	if((len%2)==0)
	{
		for(i=(len/2);i<len;i++)
		{
			rh.push_back(ref[i]);
		}
	}
	else
	{
		for(i=(len/2)+1;i<len;i++)
		{
			rh.push_back(ref[i]);
		}
	}
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
