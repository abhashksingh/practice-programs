#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <algorithm>

using namespace std;

class enemyMissile
{
	public:
		int t,f;
};
bool myfunction (enemyMissile i,enemyMissile j)
{
	bool ret= (i.f<j.f);
	if(i.f==j.f)
	{
		ret=(i.t<j.t);
	}
	return ret;
}

int main()
{
	enemyMissile tempM;
	vector <enemyMissile>mis;
	int i,N,numRequired=1,last;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>tempM.t>>tempM.f;
		mis.push_back(tempM);
	}
	sort(mis.begin(),mis.end(),myfunction);
	last=mis[0].t;
	for(i=1;i<N;i++)
	{
		if(mis[i].f==mis[i-1].f)
		{
			continue;
		}
		else if((mis[i].f-mis[i-1].f)>abs(mis[i].t-last))
		{
			last=mis[i].t;
			numRequired++;
		}
		//cout<<mis[i].t<<"  "<<mis[i].f<<endl;
	}
	cout<<numRequired<<endl;
}
