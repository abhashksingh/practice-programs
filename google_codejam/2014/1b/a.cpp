#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <cmath>
#include <map>

using namespace std;

string findUniqueString(string inp,long long &opreq);
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
			string tt;
			getline(cin,tt);
			inp[j] = tt;
			string t= findUniqueString(inp[j],res);
			sort(t.begin(),t.end());
			uniq[j] = t;
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
		//delete inp,uniq;
	}
}

string findUniqueString(string inp,long long &opreq)
{
	opreq=0;
	string ret = "";
	bool uniq[256] = {false};
	bool visited[256] = {false};
	int lim = inp.size();
	for(int i=0;i<lim;i++)
	{
		if(!uniq[inp[i]])
		{
			uniq[inp[i]]=true;
			ret+=inp[i];
		}
		else if(uniq[inp[i]])
		{
			if(!visited[inp[i]])
			{
				opreq++;
				visited[inp[i]]=true;
			}
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
