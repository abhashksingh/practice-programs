#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int max,        // maximum value of m to be used
		m, n,       // control variables for loops
		t1, t2, t3; // pythagorean triple
		// enter and validate max
	do
	{
		cout << "Enter a maximum value for m ( >1 ): ";
		cin >> max;
	}
	while (max < 2);
		// loop on m from 2 to max
	for (m=2; m <= max; m++)
	{
		// now loop on n from 1 to m-1
		for (n=1; n < m; n++)
		{
			// evaluate and print triple
			t1 = m*m-n*n;
			t2 = 2*m*n;
			t3 = m*m+n*n;
			cout << t1<<" "<< t2<< " "  << t3<< endl;
		}
	}
}
