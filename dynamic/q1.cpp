/*A child is running up a staircase with n steps,and can hop either 1 step,2 steps or 3 steps at a time.Implement a method to count how many
 *  possible ways the child can run up the stairs*/
#include <iostream>

using namespace std;
long long numStairRecursion(int n);
long long numStairDP(int n,int map[]);
int main()
{
	int numStairs;
	cin>>numStairs;
	int map[numStairs];
	for(int i=0;i<numStairs;i++)
	{
		map[i]=0;
	}
	cout<<"Using Recursion :"<<numStairRecursion(numStairs)<<endl;
	cout<<"Using Dynamic Programming :"<<numStairDP(numStairs,map)<<endl;
}

long long numStairRecursion(int n)
{
	if(n<0)
	{
		return 0;
	}
	else if(n==0)
	{
		return 1;
	}
	else
	{
		return numStairRecursion(n-1)+numStairRecursion(n-2)+numStairRecursion(n-3);
	}
}

long long numStairDP(int n,int map[])
{
	if(n<0)
	{
		return 0;
	}
	else if(n==0)
	{
		return 1;
	}
	else if(map[n]>0)
	{
		return map[n];
	}
	else
	{
		map[n]=numStairDP(n-1,map)+numStairDP(n-2,map)+numStairDP(n-3,map);
		return map[n];
	}
}
