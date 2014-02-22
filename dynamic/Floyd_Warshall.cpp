#include <iostream>
#include <string.h>
#include <limits.h>

/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 99999

using namespace std;

void floydWarshell (int** graph,int row,int col);
void printSolution(int** dist,int row,int col);

int main()
{
	int** graph=new int*[4];
	int i=0,j=0;
	for(i=0;i<4;i++)
	{
		graph[i]=new int[4];
	}
	graph[0][0]=0;
	graph[0][1]=5;
	graph[0][2]=INF;
	graph[0][3]=10;
	graph[1][0]=INF;
	graph[1][1]=0;
	graph[1][2]=3;
	graph[1][3]=INF;
	graph[2][0]=INF;
	graph[2][1]=INF;
	graph[2][2]=0;
	graph[2][3]=1;
	graph[3][0]=INF;
	graph[3][1]=INF;
	graph[3][2]=INF;
	graph[3][3]=0;
	// Print the solution
	floydWarshell(graph,4,4);
return 0;
}

void floydWarshell (int** graph,int row,int col)
{
	/* dist[][] will be the output matrix that will finally have the shortest
	 * distances between every pair of vertices */
	int i, j, k;
	int** dist = new int*[row];
	for(i = 0; i < row; i++)
		dist[i]=new int[col];
	/* Initialize the solution matrix same as input graph matrix. Or
	 * we can say the initial values of shortest distances are based
	 * on shortest paths considering no intermediate vertex. */
	for(i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			dist[i][j] = graph[i][j];
	
	for(k=0;k<col;k++)
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				// If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist,row,col);
}

void printSolution(int** dist,int row,int col)
{
	cout<<"Following matrix shows the shortest distances between every pair of vertices "<<endl;
	for (int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<dist[i][j]<<"  ";
		}
		cout<<endl;
	}
}
