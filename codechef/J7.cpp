#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int t;
	double p, s;
	cin>>t;
	while(t--)
	{
		cin>>p>>s;
		double v1,v2,res;
		v1 = (pow((p-(sqrt(pow(p, 2)-(24*s))))/12, 2)*((p/4)-(2*((p-(sqrt(pow(p, 2)-(24*s))))/12))));
		v2 = (pow((p+(sqrt(pow(p, 2)-(24*s))))/12, 2)*((p/4)-(2*((p+(sqrt(pow(p, 2)-(24*s))))/12))));
		if(v1>v2)
		{
			res = v1;
		}
		else
		{
			res=v2;
		}
		cout<<fixed<<setprecision(2)<<res<<endl;
	}
return 0;
}
