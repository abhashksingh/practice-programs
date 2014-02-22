#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	long long n;
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		long long temp,i,j,first,last,ans=0;
		vector <long long>  lis;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			lis.push_back(temp);
		}
		sort(lis.begin(),lis.end());
		 for(i=n-1;i>=2;i--)
		{
			first=0;
			last=i-1;
			while (first<last)
			{
				if ((lis[first]+lis[last])<lis[i])
				{
					ans+=+last-first;
					first++;
				}
				else
					last--;
			}
		}
		cout<<ans<<endl;
	}
}
