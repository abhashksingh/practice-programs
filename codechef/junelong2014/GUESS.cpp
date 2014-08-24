#include <iostream>

using namespace std;

long long getGCD(long long a,long long b);
void reduce(long long &num,long long &denom);

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m,aliceEven,bobEven,aliceOdd,bobOdd;
		cin>>n>>m;
		aliceEven = n/2;
		aliceOdd = (n%2==0)?(n/2):((n+1)/2);
		bobEven = m/2;
		bobOdd = (m%2==0)?(m/2):((m+1)/2);
		long long total = m*n;
		long long evenS = (aliceEven*bobEven) + (aliceOdd*bobOdd);
		long long oddS = (aliceOdd*bobEven)+(aliceEven*bobOdd);
		reduce(oddS,total);
		cout<<oddS<<"/"<<total<<endl;
	}
return 0;
}

long long getGCD(long long u,long long v)
{
	long long t;
	while (v)
	{
		t = u; 
		u = v; 
		v = t % v;
	}
return u < 0 ? -u : u; /* abs(u) */
}

void reduce(long long &num,long long &denom)
{
	long long hcf = getGCD(num,denom);
	while(hcf>1)
	{
		num = num/hcf;
		denom = denom/hcf;
		hcf = getGCD(num,denom);
	}
}
