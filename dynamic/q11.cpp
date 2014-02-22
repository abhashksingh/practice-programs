#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string,int> hMap;
int f(string exp,bool result,int s,int e);
int Fdynamic(string exp,bool result,int s,int e);
int Fdynamic2(string exp,bool result,int s,int e);
bool foundValue(map<string, int>& input, string key);

int main()
{
	string exp;
	cout<<"Enter the expression using symbols 1,0,^,&,| : ";
	getline(cin,exp);
	cout<<exp<<endl;
return 0;
}

int f(string exp,bool result,int s,int e)
{
	if(s==e)
	{
		if(exp.at(s)=='1' && result)
			return 1;
		else if(exp.at(s)=='0' && !result)
			return 1;

		return 0;
	}
	int c=0;
	if(result)
	{
		for(int i=s+1;i<=e;i+=2)
		{
			char op=exp.at(i);
			if(op=='&')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
			}
			else if(op=='|')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='^')
			{
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
			}
		}
	}
	else if(!result)
	{
		for(int i=s+1;i<=e;i+=2)
		{
			char op=exp.at(i);
			if(op=='&')
			{
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='|')
			{
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='^')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
		}
	}
}

int Fdynamic(string exp,bool result,int s,int e)
{
	string key=""+result+s+e;
	if(foundValue(hMap,key))
	{
		return hMap[key];
	}
	if(s==e)
	{
		if(exp.at(s)=='1' && result)
		{
			return 1;
		}
		else if(exp.at(s)=='0' && !result)
		{
			return 1;
		}
		return 0;
	}
	int c=0;
	if(result)
	{
		for(int i=s+1;i<=e;i+=2)
		{
			char op=exp.at(i);
			if(op=='&')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
			}
			else if(op=='|')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='^')
			{
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
			}
		}
	}
	else if(!result)
	{
		for(int i=s+1;i<=e;i+=2)
		{
			char op=exp.at(i);
			if(op=='&')
			{
				c+=f(exp,true,s,i-1)*f(exp,false,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='|')
			{
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
			else if(op=='^')
			{
				c+=f(exp,true,s,i-1)*f(exp,true,s,i+1);
				c+=f(exp,false,s,i-1)*f(exp,false,s,i+1);
			}
		}
	}
	hMap[key]=c;
return c;
}

int Fdynamic2(string exp,bool result,int s,int e)
{
	string key=""+s+e;
	int c=0;
	if(!foundValue(hMap,key))
	{
		
	}
}

bool foundValue(map<string, int>& input, string key)
{
	map<string, int>::iterator foundIter = input.find(key);
	if (foundIter != input.end())
	{
		return true;
	}
	return false;
}
