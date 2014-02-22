#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;
unsigned long long modulo(unsigned long long a,unsigned long long b)
{
	unsigned long long x=1,y=a; // unsigned long long is taken to avoid overflow of intermediate results
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
		}
		y = (y*y); // squaring the base
		b /= 2;
	}
	return x;
}

int main()
{
	unsigned long long t,D,C;
	double L,S,res;
	cin>>t;
	while(t--)
	{
		cin>>L>>D>>S>>C;
		res=(S*pow((1+C),(D-1)));
		//res=(S*modulo((1+C),D-1));
		if(res>=L)
		{
			//cout<<res<<endl;
			cout<<"ALIVE AND KICKING"<<endl;
		}
		else
		{
			//cout<<res<<endl;
			cout<<"DEAD AND ROTTING"<<endl;
		}
	}
}
