#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>   
#include <cstring>
#include <stdio.h>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

long long* maxProduct;//i shows maximum product possible with trace of i

long long numberOfFactors(long long i);
void populateMaxProduct();

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
	}
}

void populateMaxProduct()
{
	maxProduct = new long long[2501];
	long long j;
	maxProduct[0]=0;
	maxProduct[1]=0;
	for(long long i=2;i<=2500;i++)
	{
		j=i>>1;
		maxProduct[i]=(j*(i-j));
	}
}

long long numberOfFactors(long long i)
{
	vector <long long> fact;
	long long lim = sqrt(i)+1,j=0,temp;
	for(j=1;j<lim;j++)
	{
		if(i%j==0)
		{
			fact.push_back(j);
			temp = i/j;
			if(j!=temp)
			{fact.push_back(temp);}
		}
	}
	return fact.size();
}
