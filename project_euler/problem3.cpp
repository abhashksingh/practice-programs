#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	uint64_t num =600851475143,i=1;
	while(num!=1)
	{
		i++;
		if(num%i ==0)
		{
			num=num/i;
			while(num%i==0)
			{
				num=num/i;
			}
		}
	}
	cout<<i<<endl;
return 0;
}
