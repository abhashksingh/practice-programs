#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	double Ds=0,Dt=0,D=0;
	while(t--)
	{
		cin>>Ds>>Dt>>D;
		//cout<<Ds<<"  "<<Dt<<"  "<<D<<endl;
		printf("%.6lf\n",max(0.0, max(D - Ds- Dt,max(Ds-Dt-D,Dt-Ds-D))));
	}
}
