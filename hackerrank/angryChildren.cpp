#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long N,K,t,i,t1,min=999999999999,tmin,tstart=0;
	vector<long long> lis;
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		cin>>t1;
		lis.push_back(t1);
	}
	sort(lis.begin(),lis.end());
	for(i=0;i+K<N;i++)
	{
		tmin = lis[i+K-1] - lis[i];
		if(min>tmin)
		{
			min = tmin;
		}
	}
	cout<<min<<endl;
}
