#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	bool arr[100]={false};
	int t,tem,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i = 1; i <= n; i++)
		{
			while(1)
			{
				char ch = getchar();
				if (ch != ' ') break;
				scanf("%d", &tem), arr[tem] = true;
			}
		}
		int count=0;
		for(int i=0;i<100;i++)
		{
			if(arr[i])
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}
