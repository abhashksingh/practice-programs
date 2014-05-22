#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int *ar =  new int[N];
	int *ar1 = new int[N];
	for (int i=0; i<N; i++)
		cin>>ar[i];
	for(int i=0;i<N;i++)
	{
		ar1[i]=1;      
		if(i-1>=0)
		{
			if(ar[i-1]<ar[i])
				ar1[i] = ar1[i-1]+1;
			else 
			{
				int j = i;
				while(j>0 && ar[j-1] > ar[j])
				{
					ar1[j-1] = max(ar1[j-1],ar1[j] + 1);
					j= j-1;
				}
			}
		}
	}
	int total = 0;
	for ( int i = 0; i<N ; i++)
	{
		total += ar1[i];
	}
	cout<<total;
return 0;
}
