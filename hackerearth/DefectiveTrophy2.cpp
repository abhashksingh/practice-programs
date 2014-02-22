#include <iostream>

using namespace std;

//int* arr;
int countSteps(int num);

int main()
{
	int num,t;
	cin>>t;
	//arr= new int[10001];
	while(t--)
	{
		cin>>num;
		cout<<countSteps(num)<<endl;
	}
	return 0;
}

int countSteps(int num)
{
	if(num==1 || num==0)
		return 0;
	else if(num==2)
		return 1;
	else
	{
		if( num%3==0)
		{
			return (1+countSteps(num/3));
		}
		else if(num%3==1)
		{
			return (1+countSteps((num+2)/3));
		}
		else if(num%3==2)
		{
			return (1+countSteps((num+1)/3));
		}
	}
}
