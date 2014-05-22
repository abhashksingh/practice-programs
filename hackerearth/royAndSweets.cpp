#include<iostream>
#include<algorithm>

using namespace std;

int a[1000000]={0};

inline int find_max( int a, int b )
{
	return a > b ? a : b;
}
int main()
{
	int n,s,q,max=0;
	cin>>n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> s >> q;
		a[s] = q;
		max = find_max(max,s);
	}

	for ( int i = max - 1; i >= 1; i-- )
	{
		a[i] = find_max(a[i],a[i+1]);
	}
	int g,x;
	unsigned long long int sum=0;
	cin>>g;
	for(int i=0;i<g;i++)
	{
		cin>>x;
		if(x<=max)
		sum+=((a[x])/x)*100;
	}
	cout<<sum;
return 0;
}
