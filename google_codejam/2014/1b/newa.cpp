#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <cmath>
#include <map>

using namespace std;

string findUniqueString(string inp,long long &opreq);
string findUniqueString2(string inp,long long &opreq);
bool stringEqual(string* arr,int n);

int main()
{
	int T,i;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<": ";
		long long y=0,res=0;
		int N,j;
		cin>>N;
		cin.ignore();
		string* inp = new string [N];
		string* uniq = new string [N];
		
		for(j=0;j<N;j++)
		{
			getline(cin,inp[j]);
			uniq[j] = findUniqueString2(inp[j],res);
			//sort(uniq[j].begin(),uniq[j].end());
			y+=res;
		}
		if(stringEqual(uniq,N))
		{
			cout<<y<<endl;
		}
		else
		{
			cout<<"Fegla Won"<<endl;
		}
	}
}
string findUniqueString(string inp,long long &opreq)
{
	string ret = "";
	opreq=0;
	int lim = inp.size(),i,j,k;
	for(i=1;i<lim;)
	{
		if(inp[i]==inp[i-1])
		{
			opreq++;
			//ret+=inp[i];
			if(ret[ret.size()-1]!=inp[i])
			{
				ret+=inp[i];
			}
			while(inp[i]==inp[i-1] && i<lim)
			{i++;}
		}
		else
		{
			if(i==1)
			{
				ret+=inp[i-1];
			}
			ret+=inp[i];
			i++;
		}
	}
	return ret;
}

bool stringEqual(string* arr,int n)
{
	bool ret=true;
	string ref= arr[0];
	for(int i=1;i<n;i++)
	{
		if(ref.compare(arr[i])!=0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}

string findUniqueString2(string inp,long long &opreq)
{
	string ret = "";
	opreq=0;
	int lim = inp.size(),i,j,k,count=1;
	char last = inp[0];
	for(i=1;i<lim;i++)
	{
		if(inp[i]==last)
		{
			count++;
		}
		else
		{
			ret+=last;
			if(count>=2)
			{
				opreq++;
			}
			last = inp[i];
			count=1;
		}
	}
	ret+=last;
	if(count>=2)opreq++;
	return ret;
}
