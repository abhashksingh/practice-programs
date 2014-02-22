#include <iostream>
#include <map>

using namespace std;
map<long long,long long> mapCoins;

long long exchange(long long n);

int main()
{
	long long n;
	while(cin>>n)
	{
		cout<<exchange(n)<<endl;
	}
return 0;
}

long long exchange(long long n)
{
	if(n==0||n==1)
	{
		return n;
	}
	else
	{
		if(mapCoins[n]!=0)
		{
			return mapCoins[n];
		}
		else
		{
			long long a=exchange(n/2);
			long long b=exchange(n/3);
			long long c=exchange(n/4);
			mapCoins[n]=max(a+b+c,n);
			return mapCoins[n];
		}
	}
}
