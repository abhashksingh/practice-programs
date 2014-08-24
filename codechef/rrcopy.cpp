#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	long long t,N,i=0;
	cin>>t;
	while(t--)
	{
		map<long long,long long> mapping;
		cin>>N;
		long long t;
		for(i=0;i<N;i++)
		{
			cin>>t;
			map<long long,long long>::iterator it = mapping.find(t);;
			if(it==mapping.end())
			{
				mapping.insert(pair<long long,long long>(t,1));
			}
			/*else
			{
				mapping[t]++;
			}*/
		}
		cout<<mapping.size()<<endl;
	}
}
