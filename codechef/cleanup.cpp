#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long m,n,t;
		cin>>n>>m;
		bool tasks[n];
		
		for(long long i=0;i<n;i++)
		{
			tasks[i]=false;
		}
		
		for(long long i=0;i<m;i++)
		{
			cin>>t;
			tasks[t-1]=true;
		}
		
		vector<long long>incomplete,chef,assist;
		
		for(long long i=0;i<n;i++)
		{
			if(!tasks[i])
			{
				incomplete.push_back(i+1);
			}
		}
		
		for(long long i=0;i<incomplete.size();i++)
		{
			if(i%2==0)
			{
				chef.push_back(incomplete[i]);
			}
			else if(i%2==1)
			{
				assist.push_back(incomplete[i]);
			}
		}
		for(long long i=0;i<chef.size();i++)
		{cout<<chef[i]<<" ";}
		cout<<endl;
		for(long long i=0;i<assist.size();i++)
		{cout<<assist[i]<<" ";}
		cout<<endl;
	}
return 0;
}
