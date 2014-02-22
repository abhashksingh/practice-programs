#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int tc,n,k,p,ans,a[1005],i,j,c;
	char b[5];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d%d",&n,&k,&ans);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0);
		}
		cin>>b;
		if(k==0)
		{
			printf("%d\n",ans);
			continue;
		}
		if(b[0]=='A')
		{
			for(j=0;j<n;j++)
			{
				ans&=a[j];
			}
			printf("%d\n",ans);
		}
		else if(b[0]=='O')
		{
			for(j=0;j<n;j++)
			{
				ans|=a[j];
			}
			printf("%d\n",ans);
		}
		else
		{
			if(k%2==0)
				ans=ans^0;
			else
			{
				for(j=0;j<n;j++)
				{
					ans^=a[j];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
