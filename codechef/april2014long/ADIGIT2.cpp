#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>   
#include <cstring>
#include <stdio.h>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

int* arr;
char* cstr;

int main()
{
	long long n,m,i=0,j=0,ret = 0,t,diff=0;
	scanf("%lld %lld",&n,&m);
	//string str;
	//getline(cin,str);
	cstr=new char[n+1];
	scanf("%s",cstr);
	//strncpy(cstr,str.c_str(),n);
	arr = new int[n+1];
	arr[0]=0;
	for(i=1;i<n;i++)
	{
		//arr[i]=cstr[i-1]-'0';
		ret=0;
		diff=0;
		for(j=0;j<i;j++)
		{
			diff = cstr[j]-cstr[i];
			if(diff<0) diff = - diff;
			ret+=diff;
		}
		arr[i]=ret;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&t);
		//long long diff=0;
		//for(j=0;j<t-1;j++)
		//{
			//diff = cstr[j]-cstr[t-1];
			//if(diff<0) diff = - diff;
			//ret+=diff;
		//}
		////ret = diff - ((t-1)*arr[t]);
		//if(ret<0) ret = -ret;
		cout<<arr[t-1]<<endl;
	}
	delete cstr;
}
