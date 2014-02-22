#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
long long numFactors(long long a);
bool myfunction (int i,int j) { return (i>j); }

int main()
{
	int T;
	cin>>T;
	long long a,b,temp,i,cnt,sz;
	while(T--)
	{
		cin>>a>>b;
		vector<long long> lis;
		for(i=a;i<=b;i++)
		{
			lis.push_back(numFactors(i));
		}
		sort(lis.begin(), lis.end(), myfunction);
		temp=lis[0];
		//cout<<temp<<endl;
		cnt=0;sz=lis.size();
		for(i=0;i<sz;i++)
		{
			if(lis[i]==temp)
			{
				cnt++;
			}
			else
			{break;}
		}
		cout<<cnt+1<<endl;
	}
}

long long numFactors(long long a)
{
	long long cnt=0,t,lim,i;
	lim=1+(long long)sqrt(a);
	for(i=2;i<lim;i++)
	{
		if(a%i==0)
		{
			cnt++;
			t=a/i;
			if(t!=i)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
