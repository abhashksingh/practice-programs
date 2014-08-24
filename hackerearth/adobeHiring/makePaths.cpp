#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > Q;
pair<int,int> X[100005],Y[100005];
int parent[100005],size[100005];

int getParent(int node)
{
	while(node!=parent[node])
		node=parent[node];
	return node;
}

bool take_union(int node1,int node2)
{
	int p1=getParent(node1);
	int p2=getParent(node2);
	if(p1==p2)return false;
	if(size[p1]>=size[p2])
	{
		size[p1]+=size[p2];
		parent[p2]=p1;
	}
	else
	{
		size[p2]+=size[p1];
		parent[p1]=p2;
	}
return true;
}

int main()
{
	int N,i,node1,node2;
	long long ans;
	pair<int, pair<int,int> > top;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&X[i].first,&Y[i].first);
		X[i].second=Y[i].second=i;
	}
	sort(X,X+N);
	sort(Y,Y+N);

	for(i=0;i<(N-1);i++)
	{
		Q.push(make_pair(X[i+1].first-X[i].first,make_pair(X[i].second,X[i+1].second)));
		Q.push(make_pair(Y[i+1].first-Y[i].first,make_pair(Y[i].second,Y[i+1].second)));
	}
	ans=0;
	for(i=0;i<N;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
	while(!Q.empty())
	{
		top=Q.top();
		node1=top.second.first;
		node2=top.second.second;
		if(take_union(node1,node2))
			ans+=(long long)top.first;

		Q.pop();
	}
	printf("%lld\n",ans);
return 0;
}
