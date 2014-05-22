#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

bool myfunctionDec (double i,double j) { return (i>j); }
bool myfunctionInc (double i,double j) { return (i<j); }

long long war(double* naomi,double* ken,long long len);
long long decitWar(double* naomi,double* ken,long long len);

int main()
{
	long long t,i=0,j=0;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		long long len;
		double *naomi,*ken;
		cin>>len;
		naomi = new double[len];
		ken = new double[len];
		for(j=0;j<len;j++)
		{cin>>naomi[j];}
		for(j=0;j<len;j++)
		{cin>>ken[j];}
		long long y = decitWar(naomi,ken,len);
		long long z = war(naomi,ken,len);
		cout<<"Case #"<<i<<": "<<y<<" "<<z<<endl;
		delete naomi,ken;
	}
}

long long war(double* naomi,double* ken,long long len)
{
	long long ret = 0,i=0;
	sort(naomi,naomi+len,myfunctionInc);
	sort(ken,ken+len,myfunctionInc);
	for(i=0;i<len;i++)
	{
		if(naomi[i]>ken[i])
		{ret++;}
	}
	return ret;
}

long long decitWar(double* naomi,double* ken,long long len)
{
	long long ret = 0,i=0;
	sort(naomi,naomi+len,myfunctionDec);
	sort(ken,ken+len,myfunctionInc);
	for(i=0;i<len;i++)
	{
		if(naomi[i]>ken[i])
		{ret++;}
	}
	return ret;
}
