#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

vector <long long> primes;
void preProcess();
bool isPrime(long long i);
long long findHigherPrime(long long key);


int main()
{
	preProcess();
	long long t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		long long p = findHigherPrime(a+b);
		cout<<p-(a+b)<<endl;
	}
}

void preProcess()
{
	for(long long i=2;i<=4000;i++)
	{
		if(isPrime(i))
		{primes.push_back(i);}
	}
}

bool isPrime(long long num)
{
	bool ret = true;
	long long lim =1+ sqrt(num);
	for(long long i=2;i<=lim;++i)
	{
		if(num%i==0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}

long long findHigherPrime(long long key)
{
	long long lim = primes.size(),ret;
	for(long long i=0;i<lim;i++)
	{
		if(primes[i]>key)
		{
			ret = primes[i];
			break;
		}
	}
	return ret;
}
