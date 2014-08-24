#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

class Coordinate
{
	public :
		int x,y;
		Coordinate(int a=0,int b=0)
		{
			x = a;
			y = b;
		}
};

queue <Coordinate> Q;
bool visited[150][150]={false};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dist[150][150]={0};
char input[150][150];
int a,b;

void bfs(int a1,int b1);

int main()
{
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		int c=0,d=0,e=0,f=0;
		for(int i=0;i<b;++i)
		{
			scanf("%s",input[i]);
		}
		//find start and end
		for(int i=0;i<b;++i)
		{
			for(int j=0;j<a;++j)
			{
				if(input[i][j]=='S')
				{
					c=i;d=j;
				}
				if(input[i][j]=='D')
				{
					e=i;f=j;
				}
			}
			//using bfs now to find the minimum distance
			bfs(c,d);
			//printing the result and making data structures 0
			printf("%d\n",dist[e][f]);
			for(int i=0;i<150;++i)
			{
				for(int j=0;j<150;++j)
				{
					visited[i][j]=false;
					dist[i][j]=0;
				}
			}
			while(!Q.empty())
			{
				Q.pop();
			}
		}
		cin>>a>>b;
	}
}

void bfs(int a1,int b1)
{
	Q.push(Coordinate(a1,b1));
	visited[a1][b1]=true;
	while(!Q.empty())
	{
		Coordinate pos=Q.front();
		Q.pop();
		for(int i=0;i<4;++i)
		{
			Coordinate temp = Coordinate(pos.x+dx[i],pos.y+dy[i]);
			if(temp.x>=0 && temp.x<b && temp.y>=0 && temp.y<a)
			{
				if(input[temp.x][temp.y]!='S'&& input[temp.x][temp.y]!='X')
				{
					if(visited[temp.x][temp.y]==false)
					{
						if(input[temp.x][temp.y]=='D')
						{
							visited[temp.x][temp.y]=true;
							dist[temp.x][temp.y]=dist[pos.x][pos.y];
							Q.push(temp);
						}
						else
						{
							visited[temp.x][temp.y]=true;
							dist[temp.x][temp.y]=dist[pos.x][pos.y]+(input[temp.x][temp.y]-'0');
							Q.push(temp);
						}
					}
					if(input[temp.x][temp.y]=='D' && dist[temp.x][temp.y]>dist[pos.x][pos.y])
					{
						dist[temp.x][temp.y]=dist[pos.x][pos.y];
						Q.push(temp);                      
					}
					else if(dist[temp.x][temp.y]>dist[pos.x][pos.y]+(input[temp.x][temp.y]-'0'))
					{
						dist[temp.x][temp.y]=dist[pos.x][pos.y]+(input[temp.x][temp.y]-'0');
						Q.push(temp);
					}
				}
			}
		}
	}
}
