#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool inline myfunction(long long int a,long long int b)
{
	long double d1,d2;
	d1 = (long double)log10(a)/a;
	d2 = (long double)log10(b)/b;
	if(d2 > d1)return true;
	return false;
}

long long int inline BinarySearchGreatorThan(vector<long long int >&v,long double t,long long int l,long long int r)
{
	long long int mid;
	if(l > r)return v.size();
	if(l == r)return l;
	mid = (l+r)/2;
	long double d;
	d = (long double)log10(v[mid])/v[mid];
	if( d >= t)
	{
		return BinarySearchGreatorThan(v,t,l,mid);
	}
	else if(d < t)
	{
		return BinarySearchGreatorThan(v,t,mid+1,r);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long int j;
		int nn = n;
		long double dd;
		vector<long long int > A,B;
		
		for(int i = 0;i < n;i++)
		{
			scanf("%lld",&j);
			B.push_back(j);
		}
		
		for(int i = 0;i < n;i++)
		{
			scanf("%lld",&j);
			A.push_back(j);
		}
		sort(A.begin(),A.end(),myfunction);
		int sz = A.size();
		long long int ans = 0;
		for(int i = 0;i < n;i++)
		{
			long double kk = (long double)log10(B[i])/B[i];
			ans += BinarySearchGreatorThan(A,kk,0,sz);
		}
		printf("%.6lf\n",(double)ans/nn);
	}
return 0;
}
