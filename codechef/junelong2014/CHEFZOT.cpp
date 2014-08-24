#include <iostream>

using namespace std;

int main()
{
	int lenTillZero=0,maxLenTillZero=0,n,i=0;
	cin>>n;
	int* arr = new int[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		if(arr[i] > 0)
		{
			lenTillZero++;
		}
		else if(arr[i]==0)
		{
			if(lenTillZero > maxLenTillZero)
			{
				maxLenTillZero = lenTillZero;
			}
			lenTillZero = 0;
		}
	}
	if(lenTillZero > maxLenTillZero)
	{
		maxLenTillZero = lenTillZero;
	}
	cout<<maxLenTillZero<<endl;
}
