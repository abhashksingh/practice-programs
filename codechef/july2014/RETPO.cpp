#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long x,y,sum=0,absX,absY;
		cin>>x>>y;
		absX=x;
		absY=y;
		if(x<0)
		{
			absX = (-x);
		}
		if(y<0)
		{
			absY = (-y);
		}
		if((x+y)%2==0)
		{
			//even case
			cout<<2*max(absX,absY)<<endl;
		}
		else
		{
			//odd case 
			long long diffY = absY-1;
			if(diffY<0) diffY = -diffY;
			cout<<1+2*max(absX,diffY)<<endl;
		}
	}
}
