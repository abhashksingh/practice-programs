#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool visited[1000000]={false};

class SegmentTree
{
	int *tree,size;
	public:
	SegmentTree(int *arr,int N)
	{
		int x = (int)(ceil(log2(N)))+1;
		size = 2*(int)pow(2,x);
		tree = new int[size];
		memset(tree,-1,sizeof(tree));
		initialize(0,0,N-1,arr);
	}
	void initialize(int node, int start,int end, int *array)
	{
		if (start==end)
			tree[node] = 1;
		else
		{
			int mid = (start+end)/2;
			initialize(2*node,start,mid,array);
			initialize(2*node+1,mid+1,end,array);
			tree[node] = countUniques(array,start,end);
		}
	}
	int query(int node, int start,int end, int i, int j, int *array)
	{
		int id1,id2;
		if (i>end || j<start)
			return -1;

		if (start>=i && end<=j)
			return tree[node];

		int mid = (start+end)/2;
		id1 = query(2*node,start,mid,i,j,array);
		id2 = query(2*node+1,mid+1,end,i,j,array);

		if (id1==-1)
			return id2;
		if (id2==-1)
			return id1;

 		return id1+id2;
	}
	private :
	int countUniques(int* a,int start, int end)
	{
		int ret=0;
		memset(visited,0,1000000);
		for(int i=start;i<=end;i++)
		{
			if(!visited[a[i]])
			{
				visited[a[i]]=true;
				ret++;
			}
		}
		return ret;
	}
};

int main()
{
	int n,i=0;
	cin>>n;
	int* arr = new int[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	SegmentTree tree(arr,n);
	int q,l,r;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<tree.query(0,0,n-1,l-1,r-1,arr)<<endl;
	}
}
