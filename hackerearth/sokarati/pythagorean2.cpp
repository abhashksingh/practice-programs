#include <iostream>
#include <math.h>

using namespace std;

void findTotal(long long upper)
{
	long long counter = 0,max = upper -1,m,n,t1,t2,t3;
	for (m=2; m <= max; m++)
	{
		// now loop on n from 1 to m-1
		for (n=1; n < m; n++)
		{
			t1 = m*m-n*n;
			t2 = 2*m*n;
			t3 = m*m+n*n;
			//cout << t1<<" "<< t2<< " "  << t3<< endl;
			if(t3<=upper){counter++;}
			else if(t3>upper) break;
		}
	}
	cout << counter << endl;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long p;
		cin>>p;
		findTotal(p);
	}
return 0;
}

