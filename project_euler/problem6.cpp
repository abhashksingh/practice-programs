#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	long long sum=0,sqsum=0,i;
	for(i=0;i<=100;i++)
	{
		sum+=i;
		sqsum+=(i*i);
	}
	sum=sum*sum;
	cout<<sum-sqsum<<endl;
}
