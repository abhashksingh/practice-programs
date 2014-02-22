#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	long sum=0;
	for(long i=1;i<1000;i++)
	{
		if(i%3==0 && i%5==0)
		{
			sum+=i;
		}
		else if(i%3==0)
		{
			sum+=i;
		}
		else if(i%5==0)
		{
			sum+=i;
		}
	}
	cout<<sum<<endl;
}
