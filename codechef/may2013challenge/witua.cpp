#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

long long mod;

int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

inline long long input()
{
	long long ans=0;
	char c=' ';
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans;
}

inline long long multiply(long long a,long long b) // O(1) for (a*b)%m
{
	a %= mod;
	b %= mod;
	long double res = a;
	res *= b;
	long long c = (long long)(res / mod);
	a *= b;
	a -= c * mod;
	a %= mod;
	if (a < 0) a += mod;
		return a;
}

inline long long power(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=multiply(ans,a);
		}
		a=multiply(a,a);
		b>>=1;
	}
	return ans;
}

/*
inline long long power( long long a, long long b)
{
	long long x=1,y=a; 
	while(b > 0){
		if(b%2 == 1){
			x=(x*y)%mod;
		}
		y = (y*y)%mod; // squaring the base
		b /= 2;
	}
	return x%mod;
}*/

inline bool Miller(long long p)
{
	if(p<2) return false;
	if(p!=2 && !(p&1)) return false;
	for(int i=0;i<25;i++)
	{
		if(p==b[i])return true;
		else if(p%b[i]==0)return false;
	}
	int count = 0;
	long long s=p-1;
	while(!(s&1))
	{
		s/=2;
		count++;
	}
	long long accuracy=2;
	for(int i=0;i<accuracy;i++)
	{
		long long a=rand()%(p-1)+1;
		mod=p;
		long long x=power(a,s);
		if(x == 1 || x == p-1) continue;
		int flag = 0;
		for(int i = 1; i < count; i++)
		{
			x = multiply(x,x);
			if(x == 1) return false;
			if(x == p-1)
			{
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		return false;
	}
	return true;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		//n=input();
		//n--;
		if(n == 2 || n == 3)
		{
			printf("%lld\n",n);
			continue;
		}
		if(!(n&1)) n--;
		while(1)
		{
			if(Miller(n))
			{
				printf("%lld\n",n);
				break;
			}
			n -= 2;
		}
	}
	return 0;
}
