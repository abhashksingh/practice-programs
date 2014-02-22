#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
 
using namespace std;

int limit = 100003;



int main()
{
	vector<int> list[limit];
	int n,q,x,sq,a,b,l,r,k,i,j,ans;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sq=sqrt(x);
		for(j=1;j<=sq;j++)
		{
			if(x%j==0)
			{
				a=j;
				b=x/j;
				/*Store the index of elements divisible by j*/
				if(a==b)
					list[a].push_back(i);
				else
				{
					list[a].push_back(i);
					list[b].push_back(i);
				}
			}
		}
	}
	vector<int>:: iterator low,high;
	while(q--)
	{
		cin>>l>>r>>k;
		low=lower_bound(list[k].begin(),list[k].end(),l);
		high=upper_bound(list[k].begin(),list[k].end(),r);
		ans=high-low;
		cout<<ans<<endl;
	}
return 0;
}
