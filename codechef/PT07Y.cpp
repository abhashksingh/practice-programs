#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[10002] = {false};
vector<int> graph[10002];

void dfs(int index)
{
	visited[index]=1;
	int i;
	for(i=0;i<graph[index].size();i++)
	{
		if(visited[graph[index][i]])
		continue;
		dfs(graph[index][i]);
	}
	return ;
}

int main()
{
	int N,M,i;
	cin>>N>>M;
	int from,to;
	for(i=0;i<M;i++)
	{
		cin>>from>>to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	if(M!=N-1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		dfs(0);
		//count number of visited nodes
		int visitNodes = 0;
		for(i=0;i<N;i++)
		{
			if(visited[i])
				visitNodes++;
		}
		if(visitNodes == N)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
return 0;
}
