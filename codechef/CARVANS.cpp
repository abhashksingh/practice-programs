#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int* arr = new int[n];
		int i,ret=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);
		}
		if(n==1)
		{
			cout<<1<<endl;
		}
		else
		{
			for(i=1;i<n;i++)
			{
				if(arr[i]>=arr[i-1])
				{
					arr[i] = arr[i-1];
				}
				else
				{
					ret++;
				}
			}
			printf("%d\n",ret);
		}
	}
}
