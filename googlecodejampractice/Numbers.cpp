#include <iostream>
#include <stdio.h>
#include <math.h>
 
using namespace std;
 
long long int **fast_exponentiation(long long int **A,int n);//http://en.wikipedia.org/wiki/Exponentiation_by_squaring
long long int **matrix_multiply(long long int **a,long long int **b);
int solve(int n);
 
int main()
{
	int T,i=0,index=0,n;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>n;
		n = solve(n);
		if(n>=100)
			cout<<"Case #"<<i+1<<": "<<n<<endl;
		else if (n>10 && n<100)
			cout<<"Case #"<<i+1<<": 0"<<n<<endl;
		else if (n<10)
			cout<<"Case #"<<i+1<<": 00"<<n<<endl;
	}
return 0;
}
 
long long int **matrix_multiply(long long int **a,long long int **b)
{
	long long int** c= new long long int*[2];
	for(int i = 0; i < 2; i++)
	{
		c[i] = new long long int[2];
	}
	c[0][0]=0;
	c[0][1]=0;
	c[1][0]=0;
	c[1][1]=0;
	for(int i = 0;i<2;i++)
	{
		for(int j = 0;j<2;j++)
		{
			for(int k = 0;k<2;k++)
			{
				c[i][j] = (c[i][j] + a[i][k]*b[k][j])%1000;
			}
		}
	}
return c;
}
 
long long int **fast_exponentiation(long long int** A,int n)
{
	if(n==1)
	{
		return A;
	}
	else if(n%2==0)
	{
		return fast_exponentiation(matrix_multiply(A,A),(n/2));
	}
	else if(n%2==1)
	{
		return matrix_multiply(A, fast_exponentiation(matrix_multiply(A,A),(n-1)/2));
	}
}
 
 
int solve(int n)
{
	long long int** A= new long long int*[2];
	for(int i = 0; i < 2; i++)
	{
		A[i] = new long long int[2];
	}
	A[0][0]=3;
	A[0][1]=5;
	A[1][0]=1;
	A[1][1]=3;//{{3,5},{1,3}} the matrix
	long long int** A_n;
	A_n=fast_exponentiation(A,n);
	int res=((2*A_n[0][0]))%1000;
	return res-1;
}
