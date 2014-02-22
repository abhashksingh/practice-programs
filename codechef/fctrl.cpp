#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(void)
{
	long long t;
	cin >> t;
	long long n;
	while ( t-- )
	{
		long long k = 0;
		cin >> n;
		while ( pow (5, k) <= n )
		{
			k++;
		}
		long long zeros = 0;
		for(long long i = 1; i < k; i++ )
		{
			zeros += floor ( n / pow (5, i));
		}
		cout << zeros << endl;
	}
	return 0;
}
