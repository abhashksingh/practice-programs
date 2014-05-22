#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long t;
	double b,ls,minRs,maxRs;
	cin>>t;
	while(t--)
	{
		cin>>b>>ls;
		minRs = sqrt(pow(ls,2)-pow(b,2));
		maxRs = sqrt(pow(ls,2)+pow(b,2));
		cout<<minRs<<" "<<maxRs<<endl;
	}
}
