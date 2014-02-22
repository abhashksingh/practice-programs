#include <iostream>
#include <limits.h>

using namespace std;

int findMinJumps(int arr[],int size);

int main()
{
	int arr[]= {1, 3, 6, 1, 0, 9};
	int size=sizeof(arr)/sizeof(int);
	cout<<"minimum number of jumps required is "<<findMinJumps(arr,size)<<endl;
return 0;
}

int findMinJumps(int arr[],int n)
{
	int i,j;
	if(n==0 || arr[0]==0) return INT_MAX;
	int* jumps = new int[n];
	jumps[0] = 0;
	// Find the minimum number of jumps to reach arr[i]
	// from arr[0], and assign this value to jumps[i]
	for (i = 1; i < n; i++)
	{
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && jumps[j] != INT_MAX)
			{
				jumps[i] = jumps[j] + 1;
				break;
			}
		}
	}
return jumps[n-1];
}
