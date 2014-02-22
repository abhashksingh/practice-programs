#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(int parent[], int index)
{
	if(parent[index] == -1)
		return index;
	return find(parent, parent[index]);
}

void unite(int parent[], int from, int to)
{
	int par_to,par_from;
	par_from = find(parent, from);
	par_to = find(parent, to);
	parent[par_from] = par_to;
}


bool check_cycle(vector<pair<int, int> >edges, int n)
{
	int parent[n];
	//initialize parent array
	memset(parent, -1, sizeof(int)*n);  
	for(int i = 0; i < edges.size(); i++)
	{
		int from = edges[i].first;
		int to = edges[i].second;
		int par_to,par_from;
		par_to = find(parent, to);
		par_from = find(parent, from);
		if(par_from == par_to)         //cycle is there
			return false;
		unite(parent, from, to);
	}
	return true;
}

int main()
{
	vector<pair<int, int> >edges;
	int num_edges,num_vert;
	cin>>num_vert>>num_edges;
	for(int i = 0; i < num_edges; i++)
	{
		int from, to;
		cin>>from>>to;
		edges.push_back(pair<int, int>(from,to));
	}
	
	if(num_edges == num_vert-1 && check_cycle(edges, num_vert))
	{
		cout<<"is a tree"<<endl;
    }
	else
	{
		cout<<"is not a tree"<<endl;
    }
}
