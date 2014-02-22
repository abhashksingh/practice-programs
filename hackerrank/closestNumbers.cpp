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
	long long t,temp,i=0,diff;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>temp;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),myfunction);
	diff=vec[1]-vec[0];
	for(i=0;i<t-1;i++)
	{
		if((vec[i+1]-vec[i])<diff)
		{
			diff=vec[i+1]-vec[i];
		}
	}
	for(i=0;i<t-1;i++)
	{
		if((vec[i+1]-vec[i])==diff)
		{
			cout<<vec[i]<<" "<<vec[i+1]<<" ";
		}
	}
	cout<<endl;
}


bool myfunction (long long i,long long j)
{
	return (i<j);
}
