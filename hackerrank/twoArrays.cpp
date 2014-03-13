#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool myfunction (int i,int j) { return (i>j); }

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long t,n,k,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<long long> arr1,arr2;
		for(long long i=0;i<n;i++)
		{
			cin>>temp;
			arr1.push_back(temp);
		}
		for(long long i=0;i<n;i++)
		{
			cin>>temp;
			arr2.push_back(temp);
		}
		sort(arr1.begin(),arr1.end());
		sort(arr2.begin(),arr2.end(),myfunction);
		bool con=true;
		for(long long i=0;i<n;i++)
		{
			if(arr1[i]+arr2[i] < k)
			{
				con = false;
				break;
			}
		}
		if(con)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
return 0;
}
