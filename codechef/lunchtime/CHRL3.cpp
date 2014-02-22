#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> terms;
int N;
int A[100010];

int bin(int tar)
{
	int hi,lo,mid;
	lo = 0;
	hi = terms.size()-1;
	while(lo < hi)
	{
		mid = lo+(hi-lo)/2;
		if(terms[mid] > tar)
		{
			lo = mid+1;
		}
		else
		{
			hi = mid;
		}
	}

	if(terms[lo] > tar) return lo+1;
	return lo;
}

int main()
{
	int i,pos;
	scanf("%d",&N);
	for(i = 0; i < N; ++i)
	{
		scanf("%d",&A[i]);
	}
	terms.push_back(A[0]);
	for(i = 1; i < N; ++i)
	{
		pos = bin(A[i]);
		if(pos == terms.size())
		{
			terms.push_back(A[i]);
		}
		else
		{
			terms[pos] = A[i];
		}
	}
	printf("%d\n",terms.size());
return 0;
} 
