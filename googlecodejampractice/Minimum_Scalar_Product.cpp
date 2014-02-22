#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N,index=0,i=0,n;
	cin>>N;
	int c;
	for(i=0;i<N;i++)
	{
		cin>>n;
		vector<long long> a,b;
		long long min=0;
		for(index=0;index<n;index++)
		{
			cin>>c;
			a.push_back(c);
		}
		for(index=0;index<n;index++)
		{
			cin>>c;
			b.push_back(c);
			b[index]*=-1;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(index=0;index<n;index++)
		{
			b[index]*=-1;
			min+=(a[index]*b[index]);
		}
		cout<<"Case #"<<i+1<<": "<<min<<endl;
	}
}
