#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	long long t,n;
	scanf("%lld",&t);
	//cin>>t;
	while(t--)
	{
		scanf("%lld",&n);//cin>>n;
		long long p = (long long)floor(log(n)/log(2));
		cout<<(1<<p)<<endl;//printf("%lld\n",(1<<p));
	}
}
