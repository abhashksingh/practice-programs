#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

int* getDigitCount(int n)
{
	int m=n,k=0,ones=0;  
	while(m)
	{
		ones=ones*10+1;  
		k++;
		m=m/10;
	}
	int *d = new int[10];
	int tens=ceil(pow(10,k-1));
	int i,j;
	while(tens)
	{
		int dig=(n/tens)%10;
		int rest=n%tens;
		k--;
		for(i=0;i<10;i++)
		{
			d[i]=d[i]+((dig*(tens/10)*k));
		}
		for(i=0;i<dig;i++)
		{
			d[i]=d[i]+tens;
		}
		d[dig]+=(rest+1);
		tens/=10;
	}
	d[0]=d[0]-ones;
	return d;
}

int main()
{
	int n=1;  
	int *dig,i;  
	dig=getDigitCount(n);  
	for(i=0;i<10;i++)
	{
		cout<<dig[i]<<endl;
	}
return 0;
}
