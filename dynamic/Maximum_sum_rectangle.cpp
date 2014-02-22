#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

int maxarraysum(int** a,int roe,int column);
int kadane(int* arr, int* start, int* finish, int n);

int main()
{
	int** array;
	int row=4,i=0,j=0;
	int col=5;
	array = new int*[row];
	for(i=0;i<row;i++)
	{
		array[i]=new int[col];
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>array[i][j];
		}
	}
	cout<<"Maximum sum  sub-array is : "<<maxarraysum(array,row,col);
}

int maxarraysum(int** a,int row,int column)
{
	// Variables to store the final output
	int maxSum = 0, finalLeft, finalRight, finalTop, finalBottom;
	int left, right, i;
	int temp[row], sum, start, finish;
	for (left = 0; left < column; ++left)
	{
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));
		// Set the right column for the left column set by outer loop
		for (right = left; right < column; ++right)
		{
			// Calculate sum between current left and right for every row 'i'
			for (i = 0; i < row; ++i)
				temp[i] += a[i][right];
			
			// Find the maximum sum subarray in temp[]. The kadane() function
			// also sets values of start and finish.  So 'sum' is sum of
			// rectangle between (start, left) and (finish, right) which is the
			//  maximum sum with boundary columns strictly as left and right.
			sum = kadane(temp, &start, &finish, row);
			// Compare sum with maximum sum so far. If sum is more, then update
			// maxSum and other output values
			if (sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}
	cout<<"(Top, Left)"<<finalTop<<"  "<<finalLeft<<endl;
	cout<<"(Bottom, Right)"<<finalBottom<<"  "<<finalRight<<endl;
return maxSum;
}

int kadane(int* arr, int* start, int* finish, int n)
{
	// initialize sum, maxSum and start
	int sum = 0, maxSum = INT_MIN, i;
	// needed if sum NEVER becomes less than 0
	*start = 0;
	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			*start = i+1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*finish = i;
		}
	}
return maxSum;
}
