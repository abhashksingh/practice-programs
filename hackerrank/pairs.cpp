#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPresent(int **ar,int size,int f);

int main()
{
	int N,K,i,count=0;
	cin>>N>>K;
	int *arr = new int[N];
	for(i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<N;i++)
	{
		if(isPresent(&arr,N,arr[i]+K))
		{
			count++;
		}
	}
	cout<<count<<endl;
return 0;
}

bool isPresent(int **ar,int size,int f)
{
	bool ret=false;
	int *arr=*ar;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==f)
		{
			ret=true;
			break;
		}
	}
return ret;
}
