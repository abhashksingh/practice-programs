#include <iostream>

using namespace std;

int main()
{
	int t, arr[10], minVal, minVal2, minIndex, minIndex2;
	cin>>t;
	while(t--)
	{
		minVal=15; minVal2=15; minIndex=-1; minIndex2=-1;
		for(int i=0; i<10; i++)
		{
			cin>>arr[i];
			if(arr[i]<minVal)
			{
				minVal=arr[i]; minIndex=i;
			}
			else if(arr[i]<minVal2 && i!=0)
			{
				minVal2=arr[i]; minIndex2=i;
			}
		}
		if(minIndex!=0)
		{
			for(;minVal>=0; minVal--)
			{
				cout<<minIndex;
			}
		}
		else if(minVal==minVal2)
		{
			for(;minVal2>=0; minVal2--)
			{
				cout<<minIndex2;
			}
		}
		else
		{
			cout<<1;
			for(;minVal>=0; minVal--) cout<<minIndex;
		}
	cout<<endl;
	}
return 0;
}
