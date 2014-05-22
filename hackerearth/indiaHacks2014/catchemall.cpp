#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction (long long i,long long j) { return (i>j); }


int main()
{
	long long k,i=0,t,ret=0;
	vector<long long> arr;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end(),myfunction);
	vector<long long> daysReady;
	//ret=k+2;//atleast k+1 days to get ready if all are 1 and 1 day to go to oak
	for(i=0;i<k;i++)
	{
		daysReady.push_back(i+arr[i]+1);
	}
	ret = 1 + *(max_element(daysReady.begin(),daysReady.end()));
	cout<<ret<<endl;
}
