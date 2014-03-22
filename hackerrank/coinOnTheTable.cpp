#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxN 50
#define maxM 50
#define infinity 1000000

int N, M, K, ti, tj;
string board[maxN];
int p[maxN][maxM];

//k represents number of steps taken
//i the starting row
//j the starting column
void dfs(int i, int j, int k, int c)
{
	if (i >= 0 && j >= 0 && i < N && j < M && c < p[i][j] && k <= K)
	{
		p[i][j] = c;
		dfs(i - 1, j, k + 1, c + !(board[i][j] == 'U'));
		dfs(i, j - 1, k + 1, c + !(board[i][j] == 'L'));
		dfs(i + 1, j, k + 1, c + !(board[i][j] == 'D'));
		dfs(i, j + 1, k + 1, c + !(board[i][j] == 'R'));
	}
}

int getMinOperations()
{
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxM; j++)
			p[i][j] = infinity;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] == '*')
			{
				ti = i;
				tj = j;
			}
	dfs(0, 0, 0, 0);
return (p[ti][tj] == infinity ? -1 : p[ti][tj]);
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	cout << getMinOperations() << endl;
return 0;
}
