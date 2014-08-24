#include <iostream>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i=0,evenCount=0;
		cin>>n>>k;
		int* arr = new int[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]%2 == 0)
			{
				evenCount++;
			}
		}
		if(k==0 && evenCount==n)
		{
			cout<<"NO"<<endl;
		}
		else if(evenCount>=k)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
