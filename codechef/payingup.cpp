//marcha1
#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<long long>& set,long long n,long long sum);

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,sum,i,t;
		cin>>n>>sum;
		vector<long long>set;
		for(i=0;i<n;i++)
		{
			cin>>t;
			set.push_back(t);
		}
		if(isSubsetSum(set,n,sum))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
return 0;
}

bool isSubsetSum(vector<long long>& set,long long n,long long sum)
{
	bool ret = false;
	bool subset[sum+1][n+1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[0][i] = true;

	// If sum is not 0 and set is empty, then answer is false
	for (int i = 1; i <= sum; i++)
		subset[i][0] = false;

	// Fill the subset table in botton up manner
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1])
				subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
		}
	}
	
return subset[sum][n];
}
