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

int main()
{
	int t;
	unsigned long long N;
	cin>>t;
	while(t--)
	{
		cin>>N;
		cout<<modulo(2,N)-1<<endl;
	}
}
