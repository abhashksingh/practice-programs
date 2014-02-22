#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;



bool isperfect(long long a)
{
	bool ret=true;
	long long t=a,i;
	while(t>0)
	{
		i=t%10;
		if(i==2||i==3||i==5||i==6||i==7||i==8)
		{
			ret=false;
			break;
		}
		t=t/10;
	}
	return ret;
}

int main()
{
	int t;
	long long a,b,sqra,sqrb,i,check,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		count=0;
		sqra=(long long)ceil(sqrt(a));
		sqrb=(long long)floor(sqrt(b));
		for(i=sqra;i<=sqrb;i++)
		{
			check=i*i;
			/*if(i==648)
			{
				count++;
				cout<<i<<"   "<<check<<endl;
			}*/
			/*else*/
			if(isperfect(check))
			{
				count++;
				//cout<<i<<"   "<<check<<endl;
			}
		}
		//printf("%lld\n",count);
	}
}
