#include <iostream>
using namespace std;
void findnext(int &next,float* prob, int* disfr0,int L);

int main()
{
	int n,L,D,i=0;
	cin>>n>>L>>D;
	float *p = new float[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	int* disFrO = new int[n];
	for(i=0;i<n;i++)
	{
		cin>>disFrO[i];
	}
	int dis=0;
	int current=0;
	float prob=1.0;
	bool end=false;
	while(!end)
	{
		if(dis==D)
		{
			end=true;
		}
		findnext(current,p,disFrO,L);
		dis=disFrO[current];
		prob*=p[current];
	}
}

void findnext(int &current,float* prob, int* disfr0,int L)
{
	float max,t1,t2;
	int next=current+1;
	while(disfr0[current]+L>=disfr0[next])
	{
		t1=prob[next]*(disfr0[next]-disfr0[next-1]);
		t2=prob[next+1]*(disfr0[next+1]-disfr0[next]);
	}
	current=next;
}
