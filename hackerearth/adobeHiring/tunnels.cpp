#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int MAXN = 100050;

struct Edge
{
	int v1,v2,len;
}edge[2*MAXN];

struct Node
{
	int x, idx;
}s1[MAXN], s2[MAXN];

int n, fa[MAXN];

int findfa(int x)
{
	if(fa[x] == x)return x;
	return fa[x] = findfa(fa[x]);
}

bool cmp(const Node &s, const Node &t)
{
	return s.x < t.x;
}

bool cmp2(const Edge &s, const Edge &t)
{
	return s.len < t.len;
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 0 ; i < n ; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			s1[i].idx = s2[i].idx = i;
			s1[i].x = x;
			s2[i].x = y;
		}
		sort(s1, s1 + n, cmp);
		sort(s2, s2 + n, cmp);

		int tot = 0;
		for(int i = 1 ; i < n ; i++)
		{
			edge[tot].v1 = s1[i - 1].idx;
			edge[tot].v2 = s1[i].idx;
			edge[tot++].len = s1[i].x - s1[i - 1].x;
			edge[tot].v1 = s2[i - 1].idx;
			edge[tot].v2 = s2[i].idx;
			edge[tot++].len = s2[i].x - s2[i - 1].x;
		}

		sort(edge, edge + tot, cmp2);
		for(int i = 0 ; i < n ; i++)fa[i] = i;

		int now = 0;
		long long ans = 0;
		for(int i = 0 ; i < tot ; i++)
		{
			int v1 = edge[i].v1, v2 = edge[i].v2;
			if(findfa(v1) == findfa(v2))continue;
			now++;
			ans += edge[i].len;
			fa[fa[v1]] = fa[v2];
			if(now == n - 1)break;
		}
		cout<<ans<<endl;
	}
return 0;
}
