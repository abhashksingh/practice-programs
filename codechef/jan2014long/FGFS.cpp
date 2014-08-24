#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#define get getchar_unlocked

using namespace std;

class preference
{
	public:
	long s,f,p;
	preference (long a,long b,long c)
	{
		s=a;
		f=b;
		p=c;
	}
};

inline long int INP( )
{
	int n = 0 , s = 1 ; char p = get( ) ;
	if(p == '-') s = -1 ;
	while((p < '0' || p > '9') && p != EOF && p != '-')
	p = get( ) ;
	if(p == '-') s=-1 , p=get( );
	while(p >= '0' && p <= '9')
	n = (n << 3) + (n << 1) + (p - '0'), p = get( ) ;
	return n * s ;
}

inline int INP_int( )
{
	int n = 0 , s = 1 ; char p = get( ) ;
	if(p == '-') s = -1 ;
	while((p < '0' || p > '9') && p != EOF && p != '-')
	p = get( ) ;
	if(p == '-') s=-1 , p=get( );
	while(p >= '0' && p <= '9')
	n = (n << 3) + (n << 1) + (p - '0'), p = get( ) ;
	return n * s ;
}

bool myfunction (preference a,preference b)
{
	if(a.p!=b.p)
		return a.p<b.p;
	else if(a.p==b.p)
		return a.f<b.f;
}

int main()
{
	long t,K,si,fi,pi;
	int N,i;
	scanf("%ld",&t);//cin>>t;
	while(t--)
	{
		//scanf("%lld %lld",&N,&K);
		N= INP_int();
		K= INP();
		vector <preference> prefs;
		long res,j,k,l;
		for(i=0;i<N;i++)
		{
			//scanf("%lld %lld %lld",&si,&fi,&pi);
			si=INP();
			fi=INP();
			pi=INP();
			preference pr(si,fi,pi);
			prefs.push_back(pr);
		}
		sort(prefs.begin(),prefs.end(),myfunction);
		long count=0,temp=0;
		if(N>0)
			count=1;
		for(i=1;i<N;i++)
		{
			if((prefs[i].p!=prefs[i-1].p) || (prefs[i].s>=prefs[i-1].f))
			{
				++count;
			}
			else
			prefs[i].f=prefs[i-1].f;
		}
		printf("%ld\n",count);//cout<<count<<endl;
	}
	return 0;
}
