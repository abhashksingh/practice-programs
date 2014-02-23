#include <iostream>
#include <math.h>
using namespace std;

bool func(int* a,int i,int j,int sum);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin >> n;
		int* a = new int[n];
		int sum;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cin >> sum;
		if(func(a,0,n-1,sum)==true)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
return 0;
}

bool func(int* a,int i,int j,int sum)
{
	if(i>j)
		return false;
	else
	{
		if((sum-a[i])==0)
		{
			return true;
		}
		else
		{
		bool value = func(a,i+1,j,sum-a[i]);
		if(value)
			return true;
		else
			return func(a,i+1,j,sum);
		}
	}
}
