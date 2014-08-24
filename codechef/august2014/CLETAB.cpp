#include <iostream>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <cmath>
 
 
using namespace std;
 
int main()
{
	int testcase,n,m;
	scanf("%d",&testcase);
	int tables[210],sequence[410],hashtable[410][410];
	while(testcase--)
	{
		int timeSeated[410]={0},timeSeated2[410]={0},seatedOrNot[410]={0},ans=0;
		scanf("%d %d",&n,&m);
		int numFreeTables=n,counter=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&sequence[i]);
			hashtable[sequence[i]][timeSeated[sequence[i]]]=i;
			timeSeated[sequence[i]]++;
		}
		for(int i=0;i<m;i++)
		{
			if(seatedOrNot[sequence[i]])
			{
				timeSeated2[sequence[i]]++;
				continue;
			}
			if(numFreeTables)
			{
				numFreeTables--;
				ans++;
				tables[counter++]=sequence[i];
				seatedOrNot[sequence[i]]=1;
				timeSeated2[sequence[i]]++;
			}
			else
			{
				counter=0;
				if(timeSeated2[tables[0]]<timeSeated[tables[0]])
				{
					int mindist=hashtable[tables[0]][timeSeated2[tables[0]]];
					for(int j=1;j<n;j++)
					{
						int index=tables[j];
						if(timeSeated2[index]>=timeSeated[index])
						{
							counter=j;break;
						}
						if(hashtable[index][timeSeated2[index]]>mindist)
						{
							counter=j;
							mindist=hashtable[index][timeSeated2[index]];
						}
					}
				}
				int index=tables[counter];
				seatedOrNot[index]=0;
				tables[counter]=sequence[i];
				ans++;
				seatedOrNot[sequence[i]]=1;
				timeSeated2[sequence[i]]++;
			}
		}
		printf("%d\n",ans);
	}
}
