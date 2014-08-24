//use dfs with aaray just visit every node as descrived in the problem

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
 
int a [1000 + 5];
bool vis [1000 + 5];
vector <int> v [1000 + 5];
int in = 0;
 
void traverse (int s)
{
	while ( !vis [s] )
	{
		v [in].push_back (s);
		vis [s] = true;
		s = a [s];
	}

	v [in].push_back (s);
	in++;
}
 
int main ()
{
	int n;
	scanf ("%d", &n);

	for ( int i = 1; i <= n; i++ )
		scanf ("%d", &a [i]);

	memset (vis, false, sizeof (vis));

	for ( int i = 1; i <= n; i++ )
	{
		if ( !vis [i] )
		{
			traverse (i);
		}
	}

	printf ("%d\n", in);

	for ( int i = 0; i < in; i++ )
	{
		printf ("%d", v [i] [0]);
		for ( unsigned int j = 1; j < v [i].size (); j++ )
			printf (" %d", v [i] [j]);
		printf ("\n");
	}

	return 0;
}
