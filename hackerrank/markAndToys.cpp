#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	long long n,i,money,temp;
	cin>>n>>money;
	vector<long long> arr;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());
	temp=0;
	for(i=0;i<n;i++)
	{
		temp+=arr[i];
		if(temp>money)
		{  
			cout<<i<<endl;
			break;
		}
	}
return 0;
}
