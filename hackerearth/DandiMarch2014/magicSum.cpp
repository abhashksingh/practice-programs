#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

long long T,N,maxSum=INT_MIN;
vector<long long> data;

long long setMaximum(long long i)
{
	if(i>=N)
	{
		return 0;
	}
	else
	{
		long long val1=setMaximum(2*i);
		long long val2=setMaximum(2*i+1);
		long long temp=val1+val2+data[i];
		if(temp>maxSum)
		{
			maxSum=temp;
		}
		return (data[i]+max(val1,val2));
	}
}

int main()
{
	cin>>T;
	while(T--)
	{
		long long t;
		cin>>N;
		N++;
		data.resize(N);
		for(long long i=1;i<N;i++)
		{
			cin>>data[i];
		}
		setMaximum(1);
		cout<<maxSum<<endl;
	}
}
