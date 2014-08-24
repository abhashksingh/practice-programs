#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long k,c,i=0,te,sum=0;
		cin>>k>>c;
		//long long* arr = new long long[k];
		for(i=0;i<k;i++)
		{
			cin>>te;
			sum+=te;
		}
		if(sum<=c){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}
}
