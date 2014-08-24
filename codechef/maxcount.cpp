#include <iostream>
using namespace std;

int main()
{
	int t, n, b, index, arr[10005], max, temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		 b=n;
		for(int i=0; i<10005; i++)
		{
			arr[i]=0;
			max=0;
		}
		while(b--)
		{
			cin>>index; arr[index]++;
		}
		for(int i=0; i<10005; i++)
		{
			if(arr[i]>max)
			{
				max=arr[i]; temp=i;
			}
		}
		cout<<temp<<" "<<max<<endl;
	}
return 0;
} 
