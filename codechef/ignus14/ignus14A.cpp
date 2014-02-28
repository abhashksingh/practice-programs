#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int findMinAndFar(int *a,int d,int &pos)
{
	int ret=INT_MAX;
	for(int i=0;i<d;i++)
	{
		if(a!=NULL)
		{
			if(ret>=*a)
			{
				ret = *a;
				pos = i+1;
				a++;
			}
		}
	}
	return ret;
}

int main()
{
	int t,n,d;
	scanf("%d",&t);
	while(t--)
	{
		int prt=0;
		int *cst,*tcst;
		scanf("%d %d",&n,&d);
		cst = new int[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&cst[i]);//cin>>cst[i];
		}
		tcst = cst;
		prt = cst[0]+cst[n-1];
		if(n==2)
		{
			printf("%d\n",prt);
		}
		else
		{
			int temp=0,next=0;
			for(int i=0;i<n-d;i+=next)
			{
				temp+=findMinAndFar(tcst+1,d,next);
				tcst = tcst+next;
			}
			printf("%d\n",prt+temp);
		}
		delete cst;
		cst=NULL;
		tcst=NULL;
	}
}

