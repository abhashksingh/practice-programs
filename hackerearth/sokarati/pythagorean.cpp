#include <iostream>
#include <stdlib.h>

typedef unsigned long long xint;
typedef unsigned long ulong;

using namespace std;

inline ulong gcd(ulong m, ulong n)
{
	ulong t;
	while (n) { t = n; n = m % n; m = t; }
	return m;
}

xint findTotal(xint maxp)
{
	ulong a, b, c, pytha = 0, prim = 0;
	xint aa, bb, cc;
 
	for (a = 1; a <= maxp / 3; a++)
	{
		aa = (xint)a * a;
		//printf("a = %lu\r", a); /* show that we are working */
		//fflush(stdout);
 
        /*  maxp/2: valid limit, because one side of triangle
         *  must be less than the sum of the other two
         */
		for (b = a + 1; b < maxp/2; b++)
		{
			bb = (xint)b * b;
			for (c = b + 1; c < maxp/2; c++)
			{
				cc = (xint)c * c;
				if (aa + bb < cc) break;
				if (a + b + c > maxp) break;
 
				if (aa + bb == cc)
				{
					pytha++;
					if (gcd(a, b) == 1) prim++;
				}
			}
		}
	}
	return pytha;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long p,maxp;
		cin>>p;
		maxp=(2.5)*p;
		cout<<findTotal(maxp)<<endl;
	}
return 0;
}
