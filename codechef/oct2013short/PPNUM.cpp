#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	long long t,L,R,i,sum=0,c=1000000007,d1,d2,n,x;
	cin>>t;
	while(t--)
	{
		cin>>L>>R;
		d1=floor(log10(L))+1;
		d2=floor(log10(R))+1;
		sum=0;
		if(d1==d2)
		{
			n=R-L;
			sum=((L*(n+1))+(n*(n+1)/2))*d1;
		}
		else
		{
			while(d1!=d2)
			{
				x=pow(10,d1)-1;
				n=x-L;
				sum+=(((((L*(n+1))%c)+((n*(n+1)/2))*d1)%c)%c);
				d1++;
				L=x+1;
			}
			n=R-L;
			sum+=((((L*(n+1))+(n*(n+1)/2))*d1)%c);
		}
	cout<<(sum%c)<<endl;
	}
return 0;
}
