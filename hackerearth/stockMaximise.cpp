#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxProfit(vector<long long> &arr);

int main()
{
	long long t,N,temp;
	cin>>t;
	while(t--)
	{
		vector <long long> prices;
		cin>>N;
		for(long long i = 0;i<N;i++)
		{
			cin>>temp;
			prices.push_back(temp);
		}
		cout<<maxProfit(prices)<<endl;
	}
}

long long maxProfit(vector<long long> &arr)
{
	long long N =arr.size(),m=0,prof=0,i,a;
	for(i=N-1;i>=0;i--)
	{
		a=arr[i];
		if(m<=a){m=a;}
		prof+=(m-a);
	}
	return prof;
}
