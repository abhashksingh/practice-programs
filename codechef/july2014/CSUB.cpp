#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i,sum=0;
		string inp;
		cin>>n;
		cin.ignore();
		getline(cin,inp);
		long long numberOf1s = 0;
		for(i=0;i<n;i++)
		{
			if(inp[i]=='1')
				numberOf1s++;
		}
		sum = (numberOf1s+1)*(numberOf1s)/2;
		cout<<sum<<endl;
	}
}
