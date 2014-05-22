#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long long T,i=0;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		long long E,R,N,j=0,res=0;
		cin>>E>>R>>N;
		long long* arr = new long long[N];
		for(j=0;j<N;j++)
		{cin>>arr[j];}
		delete arr;
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
}
