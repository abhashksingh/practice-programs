#include <iostream>
using namespace std;

int main()
{
	int t,N,M,i=0,j=0;
	int **arr;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		arr = new int*[N];
		for(i=0;i<N;i++)
		{
			arr[i] = new int[M];
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				cin>>arr[i][j];
			}
		}
	}
}
