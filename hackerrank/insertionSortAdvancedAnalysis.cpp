#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long  _mergeSort(long long* arr, long long* temp, long long left, long long right);
long long merge(long long* arr, long long* temp, long long left, long long mid, long long right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
long long mergeSort(long long* arr, long long array_size)
{
	long long *temp = new long long [array_size];
	long long t = _mergeSort(arr, temp, 0, array_size - 1);
	delete temp;
	return t;
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
long long _mergeSort(long long* arr, long long* temp, long long left, long long right)
{
	long long mid, inv_count = 0;
	if (right > left)
	{
		/* Divide the array into two parts and call _mergeSortAndCountInv()
		for each of the parts */
		mid = (right + left)/2;
		/* Inversion count will be sum of inversions in left-part, right-part
		and number of inversions in merging */
		inv_count  = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);
		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid+1, right);
	}
return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
long long merge(long long* arr, long long* temp, long long left, long long mid, long long right)
{
	long long i, j, k;
	long long inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* i is index for right subarray*/
	k = left; /* i is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
		/* Copy the remaining elements of left subarray
		(if there are any) to temp*/
		while(i <= mid - 1)
			temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
   (if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];
  
	/*Copy back the merged elements to original array*/
	for (i=left; i <= right; i++)
		arr[i] = temp[i];

return inv_count;
}

int main()
{
	long long t,n,*arr=NULL;
	cin>>t;
	while(t--)
	{
		cin>>n;
		arr = new long long[n] ;
		for(long long i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<mergeSort(arr,n)<<endl;
		delete arr;
	}
}
