#include<iostream>
#include<cstdio>
#include<limits.h>

using namespace std;

int smoke[100][100];
int col[100];

int color(int i,int j)
{
	int a=0;
	for(int k=i;k<=j;k++) a+=col[k];
	return a%100;     
}
 
//To find min smoke when mixtures between indexes i to j are taken.Value stored in smoke[i][j]
int findSmoke(int i,int j)
{
	if(i==j) return 0;
	if(j==i+1)
	{
		smoke[i][j]=col[i]*col[j];
		return smoke[i][j];
	}
	for(int k=j;k>i;k--)
	{
		int cur;
		if(smoke[i][k-1]!=-1)
		{
			cur=smoke[i][k-1];
		}
		else
		{
			cur=findSmoke(i,k-1);
		}
		if(smoke[k][j]!=-1)
		{
			cur+=smoke[k][j];
		}
		else
		{
			cur+=findSmoke(k,j);
		}
		cur+=color(i,k-1)*color(k,j);
		if(smoke[i][j]==-1)
		{
			smoke[i][j]=cur;
		}
		if(cur<smoke[i][j])
		{
			smoke[i][j]=cur;
		}
	}
return smoke[i][j];
}
 
int main()
{
	int t,n;
	int i,j;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				smoke[i][j]=-1;
			}
		}

		for(i=0;i<n;i++)
		{
			scanf("%d",&col[i]);
		}
		for(i=1;i<n;i++)
		{
			findSmoke(0,i);
		}
		cout<<smoke[0][n-1]<<endl;
	}
return 0;
}
