#include <iostream>
#include <float.h>
#include <math.h>

using namespace std;

int main()
{
	int x1,x2,x3,y1,y2,y3,t,i=0,min=0,max=0;
	double l1,l2,l3,s,maxar=FLT_MIN,minar=FLT_MAX;
	double *ar;
	cin>>t;
	ar = new double[t];
	for(i=0;i<t;i++)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		l1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		l2=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
		l3=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
		s=(l1+l2+l3)/2;
		ar[i]=sqrt(s*(s-l1)*(s-l2)*(s-l3));
	}
	for(i=0;i<t;i++)
	{
		if(maxar<=ar[i])
		{
			maxar=ar[i];
			max=i;
		}
		if(minar>=ar[i])
		{
			minar=ar[i];
			min=i;
		}
	}
	cout<<min+1<<" "<<max+1;
}
