#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

vector<unsigned long> arr;
void preProcess();
long long theta(unsigned long num);
int main()
{
	preProcess();
	long long t;
	unsigned long k;
	cin>>t;
	while(t--)
	{
		cin>>k;
		cout<<theta(k)<<endl;
	}
}

void preProcess()
{
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(1);
}

long long theta(unsigned long num)
{
	unsigned long len = arr.size();
	for(unsigned long i=len;i<=(num+1);i++)
	{
		if ((i%3 == 0) and (i%2 == 0))
		{
			arr.push_back( 1 + min(arr[i-1],min(arr[i/2],arr[i/3])));
		}
		else if(i%2==0)
		{
			arr.push_back( 1 + min(arr[i-1],arr[i/2]));
		}
		else if(i%3 == 0)
		{
			arr.push_back( 1 + min(arr[i-1],arr[i/3]));
		}
		else
		{
			arr.push_back( 1 + arr[i-1]);
		}
	}
	return arr[num];
}

