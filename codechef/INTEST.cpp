#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long long n,k,t,sum=0;
	scanf("%lld %lld",&n,&k);
	while(n--)
	{
		scanf("%lld",&t);
		if(t%k==0)
		{
			sum++;
		}
	}
	printf("%lld\n",sum);
return 0;
}

