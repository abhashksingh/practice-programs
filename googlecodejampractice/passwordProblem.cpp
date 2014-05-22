#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <iomanip>   
#include <map>

using namespace std;

double solve(int A, int B, double* p);

int main()
{
	int T,i=0;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<": ";
		int A,B,j=0;
		cin>>A>>B;
		double *p = new double[A];
		for(j=0;j<A;j++)
		{
			cin>>p[j];
		}
		//cout<<setprecision(6)<<solve(A,B,p)<<endl;
		printf("%.6lf\n",solve(A,B,p));
	}
}

double solve(int A, int B, double* p)
{
	// dp[A]: probability you mistyped at least one of the first A characters.
	double dp[A+1];
	dp[0] = 0.0;
	for (int i=1; i<=A; i++)
	{
		dp[i] = (1 - p[i-1]) + p[i-1] * dp[i-1];
	}
	// give up typing, just press enter, it will be wrong all the time
	double giveup = 2 + B;
	// finish it, type the rest, press enter
	double finish = (B - A) + 1 + dp[A]*(1 + B);
	double backspace = finish;
	// press backspace X times (including 0, which is the same as finish).
	for (int back = 1; back <= A; back++)
	{
		backspace = std::min(backspace, back + (B - A + back) + 1 + dp[A-back]*(1 + B) );
	}
	return std::min(giveup, backspace );
}
