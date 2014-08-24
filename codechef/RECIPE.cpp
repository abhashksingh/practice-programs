#include <iostream>
#include <vector>
using namespace std;

long long getGCD(long long a,long long b);

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i=0,t,gc;
		vector<long long> arr;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>t;
			arr.push_back(t);
		}
		gc = getGCD(arr[0],arr[1]);
		for(i=2;i<n;i++)
		{
			gc  = getGCD(gc,arr[i]);
		}
		for(i=0;i<n;i++)
		{
			arr[i] = arr[i]/gc;
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
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
