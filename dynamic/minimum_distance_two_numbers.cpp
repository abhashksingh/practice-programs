/*
 * minimum_distance_two_numbers.cpp
 * 
 * Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].
 */
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int minDist(int* arr, int n, int x, int y);

int main(int argc, char **argv)
{
	int* arr;
	arr = new int[12];
	int i=0,j=0;
	for(i=0;i<12;i++)
	{
		cin>>arr[i];
	}
	int x=3,y=6;
	cout<<"Minimum distance between x="<<x<<" and y="<<y<<" is "<<minDist(arr,12,3,6)<<endl;
return 0;
}

int minDist(int* arr, int n, int x, int y)
{
	int prev,next,i=0,min_dist=INT_MAX;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == x || arr[i] == y)
		{
			prev = i;
			break;
		}
	}
	// Traverse after the first occurence
	for ( ; i < n; i++)
	{
		if (arr[i] == x || arr[i] == y)
		{
			// If the current element matches with any of the two then
			// check if current element and prev element are different
			// Also check if this value is smaller than minimm distance so far
			if ( arr[prev] != arr[i] && (i - prev) < min_dist )
			{
				min_dist = i - prev;
				prev = i;
			}
			else
			{
				prev = i;
			}
		}
	}
return min_dist;
}

