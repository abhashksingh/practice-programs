#include <cmath>  
#include <cstdio>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
void merge(unsigned int array[],unsigned int lhs, unsigned int mid, unsigned int rhs, int &res)  
{
	unsigned int *tmp = new unsigned int[rhs-lhs+1];  
	unsigned int i = lhs, j = mid + 1, k = 0;  
	while(i <= mid && j <= rhs)  
	{  
		if(array[i] <= array[j])  
		{  
			tmp[k++] = array[i++];  
		}
		else   
		{  
			res += mid - i + 1;  
			tmp[k++] = array[j++];  
		}
	}
	while(i <= mid)  
		tmp[k++] = array[i++];  
	while(j <= rhs)  
		tmp[k++] = array[j++];

	for(i = 0; i < k; i++)  
		array[lhs+i] = tmp[i];  
	delete[]tmp;  
}

void mergesort( unsigned int array[], unsigned int lhs, unsigned int rhs, int &res)  
{
	if(lhs < rhs)  
	{
		unsigned int mid = lhs + (rhs - lhs)/2;  
		mergesort(array,lhs,mid,res);  
		mergesort(array,mid+1,rhs,res);  
		merge(array,lhs,mid,rhs,res);  
	}
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin>>T;  
	while(T--)  
	{  
		int N;  
		cin>>N;  
		unsigned int *array = new unsigned int[N];  
		for(int i = 0; i < N; i++)  
			cin>>array[i];  
		int res = 0;  
		mergesort(array,0,N-1,res);  
		cout<<res<<endl;  
		delete[]array;  
	}
	return 0;  
}
