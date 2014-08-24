#include <stdio.h>

int main()
{
	int n, i, j, k, fIndex, nfIndex, numFriend[2000], numNonFriend[2000];
	char a[2000][2000];
	long count =0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}

	for(i=0;i<n;i++)
	{
			fIndex=0;
			nfIndex=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(a[i][j]=='1')
					{
						numFriend[fIndex++] = j;
					}
					else
					{
						numNonFriend[nfIndex++]=j;
					}
				}
			}

			for(j=0;j<nfIndex;j++)
			{
				for(k=0;k<fIndex;k++)
				{
					if(a[numFriend[k]][numNonFriend[j]] == '1')
					{
						count++;
						break;
					}
				}
			}
		}
	printf("%ld",count);
return 0;
}
