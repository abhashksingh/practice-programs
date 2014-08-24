#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	long long n1,n2,n3,t,i;
	vector<long long>list1,list2,list3,uniList;
	map<long long,bool> ma;
	cin>>n1>>n2>>n3;
	for(i=0;i<n1;i++)
	{
		cin>>t;
		list1.push_back(t);
		uniList.push_back(t);
	}
	for(i=0;i<n2;i++)
	{
		cin>>t;
		list2.push_back(t);
		uniList.push_back(t);
	}
	for(i=0;i<n3;i++)
	{
		cin>>t;
		list3.push_back(t);
		uniList.push_back(t);
	}
	for(i=0;i<n1+n2+n3;i++)
	{
		bool pList1,pList2,pList3;
		pList1 = binary_search (list1.begin(), list1.end(), uniList[i]);
		pList2 = binary_search (list2.begin(), list2.end(), uniList[i]);
		pList3 = binary_search (list3.begin(), list3.end(), uniList[i]);
		
		if((pList1&&pList2)||(pList2&&pList3)||(pList1&&pList3))
		{
			ma[uniList[i]]=true;
		}
	}
	map<long long,bool>::iterator it = ma.begin();
	cout<<ma.size()<<endl;
	while(it!=ma.end())
	{
		cout<<it->first<<endl;
		it++;
	}
}
