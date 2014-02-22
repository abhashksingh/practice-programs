#include <iostream>
using namespace std;

int sumOfDigits(int num);

int main()
{
	int t,a,b,ret;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<b)
		{
			b=0;
		}
		ret=sumOfDigits(a)-sumOfDigits(b);
		while(ret>10)
		{
			ret=sumOfDigits(ret);
		}
		cout<<ret<<endl;
	}
return 0;
}

int sumOfDigits(int num)
{
	int ret=0;
	while(num>0)
	{
		ret+=(num%10);
		num= num/10;
	}
	return ret;
}

