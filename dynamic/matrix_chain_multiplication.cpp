/*
 * Matrix Chain Multiplication
 */


#include <iostream>
#include <limits.h>

using namespace std;

int chainMultiplication(int* p, int i, int j);
int chainMultiplicationDynamic();

int main(int argc, char **argv)
{
	int* arr=new int[5];
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	cout<<"Minimum number of multiplications is %d "<<chainMultiplication(arr, 1, 5-1)<<endl;
return 0;
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int chainMultiplication(int* p, int i, int j)
{
	if(i == j)
		return 0;
		
	int k;
	int min = INT_MAX;
	int count;
	// place parenthesis at different places between first and last matrix,
	// recursively calculate count of multiplcations for each parenthesis
	// placement and return the minimum count
	for (k = i; k <j; k++)
	{
		count = chainMultiplication(p, i, k) + chainMultiplication(p, k+1, j) + p[i-1]*p[k]*p[j];
		if (count < min)
			min = count;
	}
	// Return minimum count
return min;
}


// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int chainMultiplicationDynamic(int* p, int n)
{
	/* For simplicity of the program, one extra row and one extra column are
	 * allocated in m[][].  0th row and 0th column of m[][] are not used
	 * */
	int m[n][n];
	int i, j, k, L, q;
	/* m[i,j] = Minimum number of scalar multiplications needed to compute
	 * the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is
	 * p[i-1] x p[i]
	 * */
	// cost is zero when multiplying one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;
	// L is chain length.
	for (L=2; L<n; L++)
	{
		for (i=1; i<=n-L+1; i++)
		{
			j = i+L-1;
			m[i][j] = INT_MAX;
			for (k=i; k<=j-1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}
return m[1][n-1];
}
