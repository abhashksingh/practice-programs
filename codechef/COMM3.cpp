#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double r=0,d1=0,d2=0,d3=0;
		int x1,y1,x2,y2,x3,y3,g=0;
		cin>>r;
		cin>>x1>>y1;
		cin>>x2>>y2;
		cin>>x3>>y3;
		d1 = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
		d2 = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
		d3 = sqrt(pow((x1-x3),2)+pow((y1-y3),2));
		if(d1<=r)g++;
		if(d2<=r)g++;
		if(d3<=r)g++;
		
		if(g>=2)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
return 0;
}
