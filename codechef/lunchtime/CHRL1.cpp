#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// A utility function that returns maximum of two integers
long long max(long long a, long long b) { return (a > b)? a : b; }
long long maxWt(long long maxCost,long long* cost,long long* wt,long long n);

int main()
{
	long long T, n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		//cout<<n<<" "<<k<<endl;
		long long* wt = new long long[n];
		long long* cst = new long long[n];
		for(long long i=0;i<n;i++)
		{
			cin>>cst[i]>>wt[i];
		}
		cout<<maxWt(k,cst,wt,n)<<endl;
		//maxWt(k,cst,wt,n);
	}
return 0;
}

long long maxWt(long long W, long long* wt, long long* val, long long n)
{
	  long long i, w;
	long long K[n+1][W+1];
 
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
return K[n][W];
}
