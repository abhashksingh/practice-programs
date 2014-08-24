#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long secondM(vector <long long> arr);
void swap(long long &a,long long &b);

int main()
{
	long long T,i=0;
	cin>>T;
	while(T--)
	{
		vector <long long> arr,teamk;
		long long num,t;
		cin>>num;
		arr.reserve(num);
		teamk.reserve(num/2);
		for(i=0;i<num;i++)
		{
			cin>>t;
			arr.push_back(t);
		}
		sort(arr.begin(),arr.end());
		for(i=0;i<=num-1;i++)
		{
			teamk.push_back(arr[i]+arr[num-i-1]);
		}
		long diffinc=secondM(teamk);
		cout<<diffinc<<endl;
	}
return 0;
}

long long secondM(vector <long long> arr)
{
	long long max=-1,min=10000000000;
	for(int i=0;i<arr.size();i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
		if(min>arr[i])
		{
			min=arr[i];
		}
	}
	return (max-min);
}

