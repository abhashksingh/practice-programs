#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

template<class T>
class SegmentTree//for maximum in a range
{
	long long  *A,size;
	public:
	SegmentTree(long long  N)
	{
		long long  x = (long long )(ceil(log2(N)))+1;
		size = 2*(long long )pow(2,x);
		A = new long long [size];
		memset(A,-1,sizeof(A));
	}
	void initialize(long long  node, long long  start,long long  end, T *array)
	{
		if (start==end)
			A[node] = start;
		else
		{
			long long  mid = (start+end)/2;
			initialize(2*node,start,mid,array);
			initialize(2*node+1,mid+1,end,array);
			if (array[A[2*node]]>= array[A[2*node+1]])
				A[node] = A[2 * node];
			else
				A[node] = A[2 * node + 1];
		}
	}
	long long  query(long long  node, long long  start,long long  end, long long  i, long long  j, T *array)
	{
		long long  id1,id2;
		if (i>end || j<start)
			return -1;
		if (start>=i && end<=j)
			return A[node];

		long long  mid = (start+end)/2;
		id1 = query(2*node,start,mid,i,j,array);
		id2 = query(2*node+1,mid+1,end,i,j,array);

		if (id1==-1)
			return id2;
		if (id2==-1)
			return id1;

		if (array[id1]>=array[id2])
			return id1;
		else
			return id2;
	}
};
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,i=0,*arr;
		cin>>n>>k;
		arr = new long long[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(k>0)
		{
			SegmentTree<long long> s(n);
			s.initialize(1,0,n-1,arr);
			i = s.query(1,0,n-1,0,k,arr);
			long long max_so_far = 0,max_ending_here = 0,pre=i;
			for(;i<n && i!=-1;)
			{
				pre= i;
				max_ending_here = max_ending_here + arr[i];
				if(max_ending_here < 0)
					max_ending_here = 0;
				if(max_so_far < max_ending_here)
					max_so_far = max_ending_here;
				i = s.query(1,0,n-1,i+k,n-1,arr);
				if(i==pre+k){i = s.query(1,0,n-1,i+1,n-1,arr);}
			}
			cout<<max_so_far<<endl;
		}
		else
		{
			long long max=0;
			for(long long i=0;i<n;i++)
			{
				if(arr[i]>0)
				{
					max+=arr[i];
				}
			}
			cout<<max<<endl;
		}
	}
return 0;
}
