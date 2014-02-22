#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int max(int a, int b) { return a>b? a: b; }
int longestSimple(int* arr , int size);
int longestTricky(int* arr , int size);

int main()
{
	int arr[] =  {1, 0, 0, 1, 0, 1, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Size of longest subarray is simple way "<<longestSimple(arr,size)<<endl;
	cout<<"Size of longest subarray is tricky way "<<longestTricky(arr,size)<<endl;
}

int longestSimple(int* arr , int arrSize)
{
	if(arr!=NULL)
	{
		int startIndex=0,maxSize=INT_MIN,sum=0,i=0,j=0;
		for (i = 0; i < arrSize-1; i++)
		{
			sum = (arr[i] == 0)? -1 : 1;
			for (j = i+1; j < arrSize; j++)
			{
				(arr[j] == 0)? sum += -1: sum += 1;
				if(sum == 0 && maxSize < j-i+1)
				{
					maxSize = j - i + 1;
					startIndex = i;
				}
			}
		}
		if ( maxSize == -1 )
			cout<<"No such subarray"<<endl;
		else
			cout<<startIndex<<" to "<<startIndex+maxSize-1<<endl;
		return maxSize;
	}
}

int longestTricky(int* arr , int n)
{
	int maxsize=-1,startindex;
	int sumleft[n];
	int min,max;
	int i,j;
	sumleft[0] = ((arr[0] == 0)? -1: 1);
	min = arr[0]; max = arr[0];
	for (i=1; i<n; i++)
	{
		sumleft[i] = sumleft[i-1] + ((arr[i] == 0)? -1: 1);
		if (sumleft[i] < min)
			min = sumleft[i];
		if(sumleft[i] > max)
			max = sumleft[i];
	}
	//now we have to find max value of j-i such that sumleft[j] == sumleft[i]
	//we have to implement a simple hash table(an array here) to keep track of values visited
	//if any of the value matches then we can maximixe j-i and size would be j-i+1
	//now there are max-min different elements in sumLeft so size of this array should be max-min+1
	int hash[max-min+1];
	//initialising the hash array
	for (i=0; i<max-min+1; i++)
	{
		hash[i] = -1;
	}
	 for (i=0; i<n; i++)
	{
		// Case 1: when the subarray starts from index 0 if it starts from 0 sum will be zero always
		if (sumleft[i] == 0)
		{
			maxsize = i+1;
			startindex = 0;
		}
		// Case 2:for sub array not starting from 0 fill hash table value. If already filled, then use it
		if (hash[sumleft[i]-min] == -1)
		{
			hash[sumleft[i]-min] = i;
		}
		else
		{
			if((i-hash[sumleft[i]-min])>maxsize)
			{
				maxsize = i - hash[sumleft[i]-min];
				startindex = hash[sumleft[i]-min] + 1;
			}
		}
	}
	if ( maxsize == -1 )
		cout<<"No such subarray"<<endl;
    else
		cout<<startindex<<" to "<<startindex+maxsize-1<<endl;  
	return maxsize;
}
