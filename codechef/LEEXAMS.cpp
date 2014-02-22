#include <iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,i=0;
		cin>>n;
		if(n>16)
		{
			cout<<0<<endl;
		}
		else
		{
			bool *visited = new bool[17];
			for(i=0;i<17;i++)
			{
				visited[i]=false;
			}
			int *A = new int[n];
			int *B = new int[n];
			float *P = new float[n];
			for(i=0;i<n;i++)
			{
				cin>>P[i]>>A[i]>>B[i];
				P[i]=P[i]/100;
			}
			float temp1=P[0],temp2=1-P[0];
			visited[A[0]]=true;
			for(i=1;i<n;i++)
			{
				if(!visited[A[i]]&&!visited[B[i]])
				{
					temp1=temp1*1.0;
					visited[A[i]]=true;
					visited[B[i]]=true;
				}
				else if(visited[A[i]]&&!visited[B[i]])
				{
					temp1=temp1*(1-P[i]);
					visited[B[i]-1]=true;
				}
				else if(!visited[A[i]]&&visited[B[i]])
				{
					temp1=temp1*P[i];
					visited[A[i]]=true;
				}
				else if(visited[A[i]]&&visited[B[i]])
				{
					temp1=0;
					break;
				}
			}
			for(i=0;i<17;i++)
			{
				visited[i]=false;
			}
			visited[B[0]]=true;
			for(i=1;i<n;i++)
			{
				if(!visited[A[i]]&&!visited[B[i]])
				{
					temp2=temp2*1.0;
				}
				else if(visited[A[i]]&&!visited[B[i]])
				{
					temp2=temp2*(1-P[i]);
				}
				else if(!visited[A[i]]&&visited[B[i]])
				{
					temp2=temp2*P[i];
				}
				else if(visited[A[i]]&&visited[B[i]])
				{
					temp2=0;
					break;
				}
			}
			cout<<temp1+temp2<<endl;
		}
	}
return 0;
}
