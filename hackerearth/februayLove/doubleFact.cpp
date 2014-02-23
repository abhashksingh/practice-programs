#include <iostream>
#include <math.h>
using namespace std;
 
long long* factorial;
int length;
void fact(long long n,long long m);
void print();
long long countZeroes(long long n);
int main()
{
	long long fact1[5];
	fact1[0]=1;
	fact1[1]=1;
	fact1[2]=2;
	fact1[3]=6;
	fact1[4]=24;
	long long T,N,M;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		if(M==0)
		{
			cout<<0<<endl;
		}
		else if(N>=5)
		{
			cout<<0<<endl;
		}
		else
		{
			factorial = new long long[M];
			fact(fact1[N],M);
			print();
			delete(factorial);
			factorial = NULL;
		}
	}
return 0;
}

void fact(long long n,long long m)
{
	long long i,j,sum,temp;
	for(i=1;i<m;i++)
	{
		factorial[i]=0;
	}
	factorial[0]=1;
	length=1;
	for(i=2;i<=n;i++)
	{
		j=temp=0;
		while(j<length)
		{
			sum=temp+factorial[j]*i;
			factorial[j]=sum%10;
			j++;
			temp=sum/10;
		}
		while(temp>0 && length <m)
		{
			factorial[j++]=temp%10;
			temp/=10;
			length++;
		}
	}
}

void print()
{
	long long i;
	for(i=length-1;i>=0;i--)
	{
		cout<<factorial[i];
	}
	cout<<endl;
}


long long countZeroes(long long n)
{
	long long k = 0;
	while ( pow (5, k) <= n )
	{
		k++;
	}
	long long zeros = 0;
	for(long long i = 1; i < k; i++ )
	{
		zeros += floor ( n / pow (5, i));
	}
	return zeros;
}
