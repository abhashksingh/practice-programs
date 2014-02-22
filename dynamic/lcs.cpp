#include <iostream>
#include <string.h>

using namespace std;

int max(int a, int b);
int lcs_nondynamic(char* X,char* Y,int m,int n);
int lcs_dynamic(char *X, char *Y, int m, int n);

int main()
{
	string a,b;
	cout<<"Enter string1 : "<<endl;
	getline(cin,a);
	cout<<"Enter string2 : "<<endl;
	getline(cin,b); 
	int m=a.length();
	int n=b.length();
	char* X= new char[m+1];
	strcpy(X, a.c_str());
	char* Y= new char[n+1];
	strcpy(Y, b.c_str());
return 0;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

int lcs_nondynamic(char* X,char* Y,int m,int n)
{
	if (m == 0 || n == 0)
		return 0;
	if(X[m-1] == Y[n-1])
		return 1 + lcs_nondynamic(X, Y, m-1, n-1);
	else
		return max(lcs_nondynamic(X, Y, m, n-1), lcs_nondynamic(X, Y, m-1, n));
}

int lcs_dynamic(char *X, char *Y, int m, int n)
{
	int L[m+1][n+1];
	int i, j;
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	*that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
}
