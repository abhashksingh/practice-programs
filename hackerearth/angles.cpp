#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,K,i,t;

vector<int> drawAngle;
vector< int > possibleCombination;
bool all[361]={false};

void fillPossibleCombination();
void addToExisting(int k);

int main()
{
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		cin>>t;
		drawAngle.push_back(t);
	}
	fillPossibleCombination();
	for(i=0;i<K;i++)
	{
		cin>>t;
		if(all[t])
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

void fillPossibleCombination()
{
	int j=1,tmp,ang;
	vector<int>temp;
	for(i=0;i<N;i++)
	{
		j=1;
		tmp = drawAngle[i];
		if(!temp.empty())
		{temp.clear();}
		ang=(tmp*j)%360;
		while(ang!=0)
		{
			all[ang]=true;
			if(i==0)
			{
				temp.push_back((tmp*j)%360);
			}
			else
			{
				addToExisting(ang);
			}
			j++;
			ang=(tmp*j)%360;
		}
	}
}


void addToExisting(int k)
{
	int j=0,lim=possibleCombination.size();
	for(j=0;j<lim;j++)
	{
		int arg = (possibleCombination[i]+k)%360;
		if(all[arg]==false)
		{
			all[arg]=true;
			possibleCombination.push_back(arg);
		}
	}
}
