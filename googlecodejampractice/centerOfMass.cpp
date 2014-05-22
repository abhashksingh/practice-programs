#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <iomanip>   
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int t,i=0;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		double dmin,tmin;
		int numberOfCases,j;
		double xavg,yavg,zavg,Vxavg,Vyavg,Vzavg,Vxsum=0,Vysum=0,Vzsum=0,xsum=0,ysum=0,zsum=0,x,y,z,Vx,Vy,Vz;
		cin>>numberOfCases;
		for(j=0;j<numberOfCases;j++)
		{
			cin>>x>>y>>z>>Vx>>Vy>>Vz;
			xsum+=x,ysum+=y,zsum+=z,Vxsum+=Vx,Vysum+=Vy,Vzsum+=Vz;
		}
		xavg=xsum/numberOfCases;
		yavg=ysum/numberOfCases;
		zavg=zsum/numberOfCases;
		Vxavg = Vxsum/numberOfCases;
		Vyavg = Vysum/numberOfCases;
		Vzavg = Vzsum/numberOfCases;
		if(Vxavg==0&&Vyavg==0&&Vzavg==0)
		{
			tmin =0 ;
			dmin = sqrt(
					pow(xavg,2) +pow(yavg,2) +pow(zavg,2) );
			printf("%.6lf %.6lf\n",dmin,tmin);
		}
		else
		{
			tmin = -(((Vxavg*xavg)+(Vyavg*yavg)+(Vzavg*zavg))/(pow(Vxavg,2)+pow(Vyavg,2)+pow(Vzavg,2)));
			if(tmin<0){tmin=0;}
			dmin = sqrt(
				pow((xavg+(Vxavg*tmin)),2)
				+pow((yavg+(Vyavg*tmin)),2)  	 +   pow((zavg+(Vzavg*tmin)),2) );
			printf("%.6lf %.6lf\n",dmin,tmin);
		}
	}
}
