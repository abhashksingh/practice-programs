#include <iostream>
 
using namespace std;
 
int main()
{
	int N,i,j,k,friendIndex=0,nonFriendIndex = 0;
	cin>>N;
	long long count = 0;
	int* friendIndexer = new int[2005];
	int* nonFriendIndexer = new int[2005];
	char** arr = new char*[N];
	for(i=0;i<N;i++)
	{
		arr[i] = new char[N];
	}
 
	for(i=0;i<N;i++)
	{
		cin>>arr[i];
	}
 
	for(i=0;i<N;i++)
	{
		friendIndex=0;
		nonFriendIndex = 0;
		for(j=0;j<N;j++)
		{
			if(i!=j)
			{
				if(arr[i][j]=='1')
				{
					friendIndexer[friendIndex]=j;
					friendIndex++;
				}
				else
				{
					nonFriendIndexer[nonFriendIndex]=j;
					nonFriendIndex++;
				}
			}
		}
		for(j=0;j<nonFriendIndex;j++)
		{
			for(k=0;k<friendIndex;k++)
			{
				if(arr[nonFriendIndexer[j]][friendIndexer[k]] == '1')
				{
					count++;
					break;
				}
			}
		}
	}
	cout<<(count)<<endl;
}
