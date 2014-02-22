#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int **arr;
int solve(int i,int j,int N);


int main()
{
	int T,N,i,j,k;
	cin>>T;
	int* sum = new int[T];
	for(i=0;i<T;i++)
	{
		cin>>N;
		arr = new int*[N];
		for(j=0;j<N;j++)
		{
			arr[j] = new int[N];
		}
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				cin>>arr[j][k];
			}
		}
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				if(arr[j][k]==1)
				{
					sum[i]+=solve(j,k,N);
				}
			}
		}
		for(j=0;j<N;j++)
		{
			delete arr[j];
			arr[j]=NULL;
		}
		delete arr;
		arr=NULL;
	}
	for(i=0;i<T;i++)
	{
		cout<<sum[i]<<endl;
	}
}

int solve(int i,int j,int n)
{
	arr[i][j]=0;
	if(i+1<n && arr[i+1][j] == 1)
	{
		solve(i+1,j,n);
	}
	if(i-1>=0 && arr[i-1][j] == 1)
	{
		solve(i-1,j,n);
	}
	if(j+1<n && arr[i][j+1] == 1)
	{
		solve(i,j+1,n);
	}
	if(j-1>=0 && arr[i][j-1] == 1)
	{
		solve(i,j-1,n);
	}
	if(i+1<n && j+1<n && arr[i+1][j+1] == 1)
	{
		solve(i+1,j+1,n);
	}
	if(i+1<n && j-1>=0 && arr[i+1][j-1] == 1)
	{
		solve(i+1,j-1,n);
	}
	if(i-1>=0 && j+1<n && arr[i-1][j+1] == 1)
	{
		solve(i-1,j+1,n);
	}
	if(i-1>=0 && j-1>=0 && arr[i-1][j-1] == 1)
	{
		solve(i-1,j-1,n);
	}
return 1;
}
