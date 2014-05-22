#include <iostream>
#include <math.h>

using namespace std;

long long power(long long base,long long exponent);
long long StepTo10(long long a);

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long k;
		long long n;
		long long ret=0;
		cin>>k>>n;
		long long sum = (power(k,n+1)-1)/(k-1);
		long long stepto10 =StepTo10(k);
		sum+=stepto10;
		while(sum>0)
		{
			ret+=(sum%10);
			sum = sum/10;
		}
		cout<<ret<<endl;
	}
}

long long power(long long base,long long exponent)
{
	if(exponent==0)
	{
		return 1;
	}
	else if(exponent%2==0)
	{
		return power(base*base,exponent/2)%10;
	}
	else if(exponent%2==1)
	{
		return base*power(base*base,(exponent-1)/2)%10;
	}
}

long long StepTo10(long long a)
{
	long long ret = 0;
	while(a<10)
	{
		a = a*a;
		ret++;
	}
	return ret-1;
}
