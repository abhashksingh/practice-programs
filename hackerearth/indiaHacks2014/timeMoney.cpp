#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define N 20001
#define ll long long int

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll arr[N] = {};
		ll maxArray[N] ={};
		int n, k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=n-1;i>=0;i--)
		{
			arr[i] = arr[i] + maxArray[i+k+1];
			maxArray[i] = max(arr[i], maxArray[i+1]);
		}
		cout<<maxArray[0]<<endl;
	}
return 0;
}
