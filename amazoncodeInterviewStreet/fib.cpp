#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector <long long> fib;

void printCommonFactorAndFibonacci(long long t);
void populateFib();
 
int main()
{
	populateFib();
	long long T,K;
	cin>>T;
	while(T--)
	{
		cin>>K;
		printCommonFactorAndFibonacci(K);
	}
return 0;
}

void printCommonFactorAndFibonacci(long long t)
{
	long long vectStindex = 2,i;
	for(i=2;i<=t;i++)
	{
		if((t%i)==0)
		{
			for(long long j=vectStindex;j<fib.size();j++)
			{
				if((fib[j]%i==0))
				{
					cout<<fib[j]<<" "<<i<<endl;
					return;
				}
			}
		}
	}
}


void populateFib()
{
	long long t1=0,t2=1,t3,max=1000000000000000000;
	t3 = t1+t2;
	fib.push_back(t2);
	while(t3<=max)
	{
		fib.push_back(t3);
		t1=t2;
		t2=t3;
		t3=t1+t2;
	}
}
