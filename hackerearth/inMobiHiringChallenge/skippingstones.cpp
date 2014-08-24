#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,l,d,i,j;
	cin>>n>>l>>d;
	int* dist;
	double *prob,*res;
	dist = new int[n+2];
	prob = new double[n+2];
	res = new double[n+2];
	for(i=1; i<=n; i++)
	{
		cin>>prob[i];
	}
	for(i=1; i<=n; i++)
	{
		cin>>dist[i];
	}
	res[0] = 1;
	prob[0]=0; dist[0]=0;
	prob[n+1]=1.0; dist[n+1]=d;
	for(i=1; i<=n+1; i++)
	{
		for(j=0; j<i; j++)
		{
			if((dist[i]-dist[j]<=l) && (res[i] < (res[j] * prob[i])))
				res[i] = res[j] * prob[i];
		}
	}
	printf("%.6lf\n", res[n+1]);//cout<<res[n+1]<<endl;
}
