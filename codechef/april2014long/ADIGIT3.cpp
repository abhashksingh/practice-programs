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
int **valArr;
int ref[10][10]={{0,1,2,3,4,5,6,7,8,9},{1,0,1,2,3,4,5,6,7,8},{2,1,0,1,2,3,4,5,6,7},{3,2,1,0,1,2,3,4,5,6},{4,3,2,1,0,1,2,3,4,5},{5,4,3,2,1,0,1,2,3,4},{6,5,4,3,2,1,0,1,2,3},{7,6,5,4,3,2,1,0,1,2},{8,7,6,5,4,3,2,1,0,1},{9,8,7,6,5,4,3,2,1,0},};
int main()
{
	long long n,m,i=0,j=0,ret = 0,t;
	scanf("%lld %lld",&n,&m);
	//string str;
	//getline(cin,str);
	cstr=new char[n+1];
	scanf("%s",cstr);
	//strncpy(cstr,str.c_str(),n);
	arr = new int[n+1];
	for(i=0;i<n;i++)
	{
		arr[i]=cstr[i]-'0';
	}
	valArr = new int*[n];
	for(i=0;i<n;i++)
	{
		valArr[i] = new int[10];
	}
	valArr[0][arr[0]] = 1;
	for(i = 1 ;i<n;i++)
	{
		for(j= 0;j<10;j++)
		{
			if(arr[i]==j)
				valArr[i][j] = valArr[i-1][j]+1;
			else
				valArr[i][j] = valArr[i-1][j];
		}
	}
	for(i=0;i<m;i++)
	{
		ret=0;
		scanf("%lld",&t);
		//long long diff=0;
		//int u = cstr[t-1] - '0';
		for(j=0;j<10;j++)
		{
			ret+=((valArr[t-1][j])*ref[j][arr[t-1]]);
		}
		//ret = diff - ((t-1)*arr[t]);
		//if(ret<0) ret = -ret;
		//cout<<ret<<endl;
		printf("%lld\n",ret);
	}
	delete cstr,arr;
}
