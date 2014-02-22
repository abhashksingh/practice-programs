#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class preference
{
	public:
	long long s,f,p;
	preference (long long a,long long b,long long c)
	{
		s=a;
		f=b;
		p=c;
	}
};

bool myfunction (preference i,preference j) { return (i.f<j.f); }


int main()
{
	long long t,N,K,i;
	long long si,fi,pi;
	cin>>t;
	while(t--)
	{
		cin>>N>>K;
		if(N>0)
		{
			vector <preference> prefs[K];
			long long sum,res,j,k,l;
			for(i=0;i<N;i++)
			{
				cin>>si>>fi>>pi;
				preference pr(si,fi,pi);
				prefs[pi-1].push_back(pr);
			}
			sum=0;
			for(i=0;i<K;i++)
			{
				if(prefs[i].size()>0)
				{
					res=1;
					sort(prefs[i].begin(),prefs[i].end(),myfunction);
					for(j=1;j<prefs[i].size();j++)
					{
						if((prefs[i][j].s >= prefs[i][j-1].f))
						{
							res++;
						}
					}
					sum=sum+res;
				}
			}
			cout<<sum<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
return 0;
}
