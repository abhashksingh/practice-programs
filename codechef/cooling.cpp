#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i=0,tempWeight,j=0;
		cin>>n;
		vector <long long> pie,racks;
		bool occupied[n];
		
		for(i=0;i<n;i++)
		{
			cin>>tempWeight;
			pie.push_back(tempWeight);
		}
		
		for(i=0;i<n;i++)
		{
			cin>>tempWeight;
			racks.push_back(tempWeight);
			occupied[i]=false;
		}
		
		sort(pie.begin(),pie.end());
		sort(racks.begin(),racks.end());
		long long res=0;
		//placing pie on a rack
		for ( i=0, j = 0; i < n && j < n; i++)
		{
			while (j < n && pie[i] > racks[j])
				j++;
			if (j < n)
			{
				res++;
				j++;
			}
		}
		
		cout<<res<<endl;
	}
return 0;
}
