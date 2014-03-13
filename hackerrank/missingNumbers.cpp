#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<long long , long long> map1,map2;

int main()
{
	long long n1,n2,i=0,t;
	cin>>n1;
	for(i=0;i<n1;i++)
	{
		cin>>t;
		if(map1.find(t)==map1.end())
		{
			map1.insert(pair<long long , long long>(t,1));
		}
		else
		{
			map1[t]++;
		}
	}
	cin>>n2;
	for(i=0;i<n2;i++)
	{
		cin>>t;
		if(map2.find(t)==map1.end())
		{
			map2.insert(pair<long long , long long>(t,1));
		}
		else
		{
			map2[t]++;
		}
	}
	vector<long long> res;
	for(map<long long,long long> :: iterator it = map2.begin();it!=map2.end();it++)
	{
		if(map1.find(it->first)!=map1.end())
		{
			//found
			if(it->second > map1[it->first])
			{
				res.push_back(it->first);
			}
		}
		else
		{
			//not found
			res.push_back(it->first);
		}
	}
	for(vector<long long>::iterator it =res.begin();it!=res.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
return 0;
}
