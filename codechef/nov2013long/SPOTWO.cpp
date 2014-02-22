#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const unsigned long long c=1000000007;

unsigned long long modulo(unsigned long long a,unsigned long long b)
{
	unsigned long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
	while(b > 0){
		if(b%2 == 1){
			x=(x*y)%c;
		}
		y = (y*y)%c; // squaring the base
		b /= 2;
	}
	return x%c;
}

unsigned long long dectobin(unsigned long long dec)
{
	unsigned long long rem,i=1,sum=0;
	do
	{
		rem=dec%2;
		sum=sum + (i*rem);
		dec=dec/2;
		i=i*10;
	}while(dec>0);
	return sum;
}

int main()
{
	unsigned long long T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		unsigned long long res=modulo(2,dectobin(N))%c;
		cout<<((modulo(res,2))%c)<<endl;
	}
}
