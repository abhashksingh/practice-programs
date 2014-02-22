#include <iostream>
#include <string.h>
using namespace std;

int editDistance(char* a,char* b,int m,int n);
int Minimum(int a, int b, int c);

int main(int argc, char **argv)
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	//cout<<str1<<"  "<<str2<<endl;
	int m = str1.length();
	int n = str2.length();
	char* a = new char[m+1];
	char* b = new char[n+1];
	strcpy(a,str1.c_str());
	strcpy(b,str2.c_str());
	cout<<a<<"  "<<b<<endl;
	cout<<"Edit Distance : "<<editDistance(a,b,m,n)<<endl;
	return 0;
}

int editDistance(char* a,char* b,int m,int n)
{
	int T[m+1][n+1],i=0,j=0;
	for(i = 0; i <=m; i++)
		for(j = 0; j <=n; j++)
			T[i][j] = 0;
	//Set up base cases
	for(i = 0; i <= m; i++)
		T[i][0]=i;

	for(i=0;i<=n;i++)
		T[0][i]=i;
		
	for(i = 1; i <=m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1]) T[i][j] = T[i-1][j-1];
			else T[i][j] = 1 + Minimum(T[i][j-1],T[i-1][j],T[i-1][j-1]);
		}
	}
	return T[m][n];
}

int Minimum(int a, int b, int c)
{
	int min = c;
	if( a < b )
		if( a < c )
			min = a;
		else if( b < c )
			min = b;
	return min;
}
