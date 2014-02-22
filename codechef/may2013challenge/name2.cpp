#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream> 
#include <cstring>

using namespace std;

bool isSubsequence(string master,string slave);

int main()
{
	int t;
	string husband,wife,str;
	cin>>t;
	char a;
	scanf("%c",&a);
	while(t--)
	{
		getline(cin,str);
		stringstream stream(str);
		getline(stream, husband, ' ');
		getline(stream, wife, ' ');
		if(isSubsequence(husband,wife)||isSubsequence(wife,husband))
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

bool isSubsequence(string master,string slave)
{
	if(master.empty()||slave.empty())
	{
		return false;
	}
	int mlen=master.length();
	int slen=slave.length();
	if(mlen<slen)
	{
		return false;
	}
	else if(mlen==slen)
	{
		int ret=master.compare(slave);
		if(ret==0) return true;
		else return false;
	}
	else
	{
		bool ret=true;
		int pos=-1;
		for(int i=0;ret&&i<slen;i++)
		{
			ret = (pos = master.find(slave[i], pos+1)) != string::npos;
		}
		return ret;
	}
}
