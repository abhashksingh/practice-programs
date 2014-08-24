#include <iostream>

using namespace std;

int main()
{
	long long N,M,q,i;
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		cin>>q;
		long long L = max(q - N, N + 1);
		long long R = min(q - 1, 2*N);
		long long ans = 0;
		if (L > R)
		{
			ans = 0;
		}
		else
		{
			ans = R - L + 1;
		}
		cout<<ans<<endl;
	}
}
