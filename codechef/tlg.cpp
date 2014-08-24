#include <iostream>

using namespace std;

int main()
{
	long long t,a,b,suma=0,sumb=0,leadA=0,leadB=0,maxleadA=0,maxleadB=0;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		suma+=a;
		sumb+=b;
		if (suma>sumb)
		{
			leadA=suma-sumb;
		}
		else
		{
			leadB=sumb-suma;
		}
		if(leadA>maxleadA) maxleadA=leadA;
		if(leadB>maxleadB) maxleadB=leadB;
	}
	if(maxleadA>maxleadB) cout<<1<<" "<<maxleadA<<endl;
	else cout<<2<<" "<<maxleadB<<endl;
}
