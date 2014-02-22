#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

long long inline numDigits(long long num)
{
	long long ret=0;
	if(num<10)
	{
		ret=1;
	}
	else if(num>=10 && num<100)
	{
		ret=2;
	}
	else if(num>=100 && num<1000)
	{
		ret=3;
	}
	else if(num>=1000 && num<10000)
	{
		ret=4;
	}
	else if(num>=10000 && num<100000)
	{
		ret=5;
	}
	else if(num>=100000 && num<1000000)
	{
		ret=6;
	}
	else if(num>=1000000 && num<10000000)
	{
		ret=7;
	}
	else if(num>=10000000 && num<100000000)
	{
		ret=8;
	}
	else if(num>=100000000 && num<1000000000)
	{
		ret=9;
	}
	return ret;
}

int main()
{
	long long t,L,R,i,sum=0,c=1000000007;
	long long dig=1,limit;
	scanf("%lld",&t);
	//cin>>t;
	//cout<<c<<endl;
	while(t--)
	{
		sum=0;
		scanf("%lld",&L);
		scanf("%lld",&R);
		dig=numDigits(L);
		limit=(long long)pow(10,dig);
		for(i=L;i<=R;i++)
		{
			if(i>=limit)
			{
				dig=numDigits(i);
				limit=(long long)pow(10,dig);
			}
			sum = ((sum % c) + ((i*dig)% c))%c;
		}
		printf("%lld\n",sum);
		//cout<<sum<<endl;
	}
}
