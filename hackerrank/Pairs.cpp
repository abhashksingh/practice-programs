#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

bool myfunction (long long i,long long j);

int main()
{
	vector <long long> vec;
	long long t,temp,i=0,diff,count=0;
	cin>>t>>diff;
	for(i=0;i<t;i++)
	{
		cin>>temp;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),myfunction);
	for(i=0;i<t;i++)
	{
		if(binary_search(vec.begin(),vec.end(),vec[i]+diff,myfunction))
		{
			count++;
		}
	}
	cout<<count<<endl;
}

bool myfunction (long long i,long long j)
{
	return (i<j);
}
