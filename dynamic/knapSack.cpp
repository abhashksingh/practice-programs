/*
 * knapSack.cpp
 */

#include <iostream>
#include <limits.h>

using namespace std;

int knapsack(int W,int* wt,int* val,int n);
int knapsackDynamic(int W,int* wt,int* val,int n);

int main(int argc, char **argv)
{
	int* val = new int [3];
	int* wt = new int[3];
	for(int i=0;i<3;i++)
	{
		cin>>val[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>wt[i];
	}
	int W;
	cin>>W;
	cout<<"The maximum value for the given weight is "<<knapsack(W,wt,val,3)<<endl;
	cout<<"The maximum value for the given weight is "<<knapsackDynamic(W,wt,val,3)<<endl;
return 0;
}

int knapsack(int W,int* wt,int* val,int n)
{
	if(n==0||W==0)
	{
		return 0;
	}
	// If weight of the nth item is more than Knapsack capacity W, then
	// this item cannot be included in the optimal solution
	if (wt[n-1] > W)
	{
		return knapsack(W, wt, val, n-1);
	}
	// Return the maximum of two cases: (1) nth item included (2) not included
	else
	{
		return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W, wt, val, n-1));
	}
}

int knapsackDynamic(int W,int* wt,int* val,int n)
{
	int i, w;
	int K[n+1][W+1];
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
return K[n][W];
}
