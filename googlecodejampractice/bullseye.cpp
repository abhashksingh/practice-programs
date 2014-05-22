#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	long long T,i=0;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		double r,t;
		cin>>r>>t;
		double n =((1-2*r)+sqrt(pow((2*r-1),2)+8*t))/4;
		double intPart = floor(n);
		long long res = intPart;
		//if(res<0) res=0;
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
}
