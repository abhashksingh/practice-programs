#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool findNum(int **a,int size,int num);
bool checkRes(bool res[],int size);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int size,i=0;
		long long sum,s=0;
		cin>>size>>sum;
		long long *a= new long long[size];
		long long *b= new long long[size];
		bool res[size];
		for(i=0;i<size;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		for(i=0;i<size;i++)
		{
			cin>>b[i];
			s+=b[i];
		}
		long long tot=sum*size;
		
		
		if(s>=tot)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}

bool checkRes(bool res[],int size)
{
	bool ret=true;
	for(int i=0;i<size;i++)
	{
		if(res[i]==false)
		{
			ret=false;
			break;
		}
	}
	return ret;
}

bool findNum(int **a,int size,int num)
{
	int *b=new int[size];
	b=*a;
	bool ret=false;
	for(int i=0;i<size;i++)
	{
		if(b[i]==num)
		{
			ret=true;
			break;
		}
	}
	return ret;
}
