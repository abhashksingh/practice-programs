#include <iostream>
using namespace std;

int main()
{
	int R,C,i=0,j=0;
	long long **arr;
	cin>>R>>C;
	arr = new long long*[R];
	for(i=0;i<R;i++)
	{
		arr[i]=new long long[C];
	}
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int Q;
	cin>>Q;
	while(Q--)
	{
		int x1,x2,y1,y2;
		long long sum=0;
		cin>>x1>>y1>>x2>>y2;
		for(i=x1-1;i<x2;i++)
		{
			for(j=y1-1;j<y2;j++)
			{
				sum+=arr[i][j];
			}
		}
		cout<<sum<<endl;
	}
    //cout << "Hello World!" << endl;
    return 0;
}
