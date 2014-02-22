#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long binarySearch(std::vector<long long>& v, const int& key, const long long& start, const long long& end);

int main()
{
	int t,n,i,k;
	cin>>t;
	while(t--)
	{
		long long uncle,temp;
		vector <long long> A;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			A.push_back(temp);
		}
		cin>>k;
		uncle=A[k-1];
		sort(A.begin(),A.end());
		cout<<binarySearch(A,uncle,0,A.size()-1)+1<<endl;
	}
	
return 0;
}


long long binarySearch(std::vector<long long>& v, const int& key, const long long& start, const long long& end)
{
	if(end < start)
		// Set is empty, return false
		return false;
	else
	{
		// Calculate midpoint to cut set in half
		long long mid = (start + end)/2;
		if(v.at(mid) > key)
			// Key is in lower subset
			return binarySearch(v, key, start, mid-1);
		else if (v.at(mid) < key)
			// Key is in upper subset
			return binarySearch(v, key, mid+1, end);
		else
			// Key has been found
			return mid;
	}
}
