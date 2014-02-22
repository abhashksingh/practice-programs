#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int *arr;
int countSteps(int num);

int main()
{
	int num,t;
	arr= new int[10001];
	memset(arr,0,sizeof(int)*10001);
	arr[0]=0;
	arr[1]=1;
	cin>>t;
	while(t--)
	{
		cin>>num;
		if(num==1)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<countSteps(num)<<endl;
		}
	}
return 0;
}

int countSteps(int num)
{
	if(arr[num]==0 && num>0)
	{
		arr[num]=countSteps((num-2)/2)+1;
	}
	return arr[num];
}
