#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long M,N,sum=0,i,a,b,k;
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		cin>>a>>b>>k;
		sum+=((b-a+1)*k);
	}
	cout<<sum/N<<endl;
return 0;
}
