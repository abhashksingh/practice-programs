#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;
 
template<class T>
class SegmentTree
{
	long long *A,size;
	public:
	SegmentTree(long long N)
	{
		long long x = (long long)(ceil(log2(N)))+1;
		size = 2*(long long)pow(2,x);
		A = new long long[size];
		memset(A,-1,sizeof(A));
	}
	void initialize(long long node, long long start,long long end, T *array)
	{
		if (start==end)
			A[node] = start;
		else
		{
			long long mid = (start+end)/2;
			initialize(2*node,start,mid,array);
			initialize(2*node+1,mid+1,end,array);
			if (array[A[2*node]]>=array[A[2*node+1]])
				A[node] = A[2 * node];
			else
				A[node] = A[2 * node + 1];
		}
	}
	long long query(long long node, long long start,long long end, long long i, long long j, T *array)
	{
		long long id1,id2;
		if (i>end || j<start)
			return -1;

		if (start>=i && end<=j)
			return A[node];

		long long mid = (start+end)/2;
		id1 = query(2*node,start,mid,i,j,array);
		id2 = query(2*node+1,mid+1,end,i,j,array);

		if (id1==-1)
			return id2;
		if (id2==-1)
			return id1;
 
		if (array[id1]<=array[id2])
			return id1;
		else
			return id2;
	}
};
 
int main()
{
	long long i,j,N;
	long long A[1000];
	cin>>N;
	for (i=0;i<N;i++)
		cin>>A[i];

	SegmentTree<long long> s(N);
	s.initialize(1,0,N-1,A);
	while (scanf("%lld%lld",&i,&j)!=EOF)
		printf("%lld\n",A[s.query(1,0,N-1,i-1,j-1,A)]);
}
