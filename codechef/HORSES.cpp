#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,i=0,temp;
		cin>>N;
		vector<int> vec;
		for(i=0;i<N;i++)
		{
			cin>>temp;
			vec.push_back(temp);
		}
		sort(vec.begin(),vec.end());
		int diff = vec[1]-vec[0],mdiff;
		mdiff = diff;
		for(i=1;i<N-1;i++)
		{
			diff = vec[i+1] - vec[i];
			if(mdiff>diff)
			{
				mdiff = diff;
			}
		}
		cout<<mdiff<<endl;
	}
return 0;
}
