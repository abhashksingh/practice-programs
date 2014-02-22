#include <iostream>

using namespace std;

int main()
{
	int n,i=0,sum=0,cost,avg;
	cin>>n;
	int *A=new int[n];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		sum+=A[i];
	}
	cin>>cost;
	avg=sum/n;
	
}
