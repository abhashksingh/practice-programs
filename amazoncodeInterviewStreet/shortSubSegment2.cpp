#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
map<string,int> toFind,hasFound;
map<string,bool> mapping;

char easytolower(char in)
{
	if(in<='Z' && in>='A')
		return in-('Z'-'z');
	return in;
}

void populateMapping(string patternArr[],int size);
void printArray(string arr[],int start,int end);
void getMinWindow(string inputArr[],int m,string pattern[],int n,int &st,int &fn);

int main()
{
	string text;
	getline(cin,text);
	int t,i,start,end;
	cin>>t;
	cin.ignore();
	string inp[t];
	for(i=0;i<t;i++)
	{
		getline(cin,inp[i]);
		transform(inp[i].begin(), inp[i].end(), inp[i].begin(), easytolower);
		//cout<<inp[i]<<endl;
	}
	//cout<<endl;
	text.erase(std::remove(text.begin(), text.end(), '.'), text.end());
	//tokenising the input text
	int spaceCount = 1+count(text.begin(), text.end(), ' ');
	string textArr[spaceCount];
	istringstream iss (text);
	for(i=0;i<spaceCount;i++)
	{
		iss >> textArr[i];
		transform(textArr[i].begin(), textArr[i].end(), textArr[i].begin(), easytolower);
	}
	/*for(i=0;i<spaceCount;i++)
	{
		cout<<textArr[i]<<endl;
	}
	for(i=0;i<t;i++)
	{
		cout<<inp[i]<<endl;
	}*/
	getMinWindow(textArr,spaceCount,inp,t,start,end);
	//cout<<start<<"  "<<end<<endl;
	printArray(textArr,start,end);
return 0;
}

void getMinWindow(string str[],int m,string s[],int n,int &st,int &fn)
{
	/*for(int i=0;i<m;i++)
	{
		cout<<str[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}*/
	populateMapping(s,n);
	st=-1;
	fn=-1;
	int cnt=0,j=0,min=INT_MAX;
	for(int i=0;i<m;i++)
	{
		//j=0;
		if(mapping.count(str[i])==0)
		{
			continue;
		}
		else
		{
			hasFound[str[i]]++;
			if(toFind[str[i]]>=hasFound[str[i]])
				cnt++;
			if(cnt==n)
			{
				while(toFind.count(str[j])==0 || hasFound[str[j]]>toFind[str[j]])
				{
					if(hasFound[str[j]]>toFind[str[j]])
					{
						hasFound[str[j]]--;
					}
					j++;
				}
				if((i-j+1)<=min)
				{
					min=i-j+1;
					st=j;
					fn=i;
				}
			}
		}
	}
}

void populateMapping(string patternArr[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		toFind[patternArr[i]]=0;
		hasFound[patternArr[i]]=0;
		mapping[patternArr[i]]=true;
	}
	for(i=0;i<size;i++)
	{
		toFind[patternArr[i]]++;
	}
	/*for(i=0;i<size;i++)
	{
		cout<<patternArr[i]<<" "<<toFind[patternArr[i]]<<endl;
	}*/
}

void printArray(string arr[],int start,int end)
{
	if(start<0 || end <0)
	{
		cout<<"NO SUBSEGMENT FOUND";
	}
	else
	{
		cout<<start<<"  "<<end<<endl;
		for(int i=start+1;i<=end;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;
}
