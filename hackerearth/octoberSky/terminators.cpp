#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b);
int lcs_dynamic(vector<int>X, vector<int> Y, int m, int n);
void find_lis(vector<int> &a, vector<int> &b);

int main(void)
{
	int t,n,i=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int t1,t2;
		vector<int>d1,lisd1,seqd1;//int* d1 = new int[n];
		vector<int>d2,lisd2,seqd2;//int* d2 = new int[n];
		for(i=0;i<n;i++)
		{
			cin>>t1>>t2;//d1[i]>>d2[i];
			d1.push_back(t1);
			d2.push_back(t2);
			//cout<<d1[i]<<"  "<<d2[i]<<endl;
		}
		find_lis(d1,seqd1);
		find_lis(d2,seqd2);
		for (size_t i = 0; i < seqd1.size(); i++)
		{
			 lisd1.push_back(d1[seqd1[i]]);
		}
		for (size_t i = 0; i < seqd2.size(); i++)
		{
			 lisd2.push_back(d2[seqd2[i]]);
		}
		//printf("%d ", d1[seqd1[i]]);
		cout<<lcs_dynamic(lisd1,lisd2,lisd1.size(),lisd2.size())<<endl;//<<endl<<endl<<endl<<endl;
	}
}

int max(int a, int b)
{
	return (a > b)? a : b;
}


int lcs_dynamic(vector<int>X, vector<int> Y, int m, int n)
{
	int L[m+1][n+1];
	int i, j;
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	*that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
}

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v; 
	if (a.empty()) return; 
	b.push_back(0); 
	for (size_t i = 1; i < a.size(); i++)
	{
		// If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i])
		{
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
		/* Binary search to find the smallest element referenced by b which is just bigger than a[i]
		* Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
		*/
		for (u = 0, v = b.size()-1; u < v;)
		{
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
		/* Update b if new value is smaller then previously referenced value */
		if (a[i] < a[b[u]])
		{
			if(u > 0)
			{
				p[i] = b[u-1];
			}
			b[u] = i;
		}
	}
 	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
