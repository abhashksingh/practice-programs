#include <iostream>
#include <climits>
using namespace std;

int main()
{
	long long t,n,i;
	long long arr,max,maxIndex;
	cin>>t;
	while(t--)
	{
		max = 0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr;
			if(arr+i>max)
			{
				max = arr+i;
			}
		}
		cout<<max<<endl;
	}
}
