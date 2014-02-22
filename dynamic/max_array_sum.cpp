#include <iostream>
#include <string.h>

using namespace std;

int maxarraysum(int* a,int size);

int main()
{
	int* a= new int[8];
	a[0]=-2;
	a[1]=-3;
	a[2]=4;
	a[3]=-1;
	a[4]=-2;
	a[5]=1;
	a[6]=5;
	a[7]=-3;
	cout<<"Maximum sum of subarray is : "<<maxarraysum(a,8)<<endl;
return 0;
}

int maxarraysum(int* a,int size)
{
	int max_so_far=0;
	int max_ending_here=0;
	for(int i=0;i<size;i++)
	{
		max_ending_here+=a[i];
		if(max_so_far<max_ending_here)
		{
			max_so_far=max_ending_here;
		}
		else if(max_ending_here<0)
		{
			max_ending_here=0;
		}
	}
return max_so_far;
}
