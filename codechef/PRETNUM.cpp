#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector <long long> perfect;
vector <long long> primes;

void populate();
void populatePrime();
bool isPrime(long long num);
bool binarySearch(std::vector<long long>& v, const int& key, const long long& start, const long long& end);

int main()
{
	int t;
	long long L,R,i,count;
	populate();
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>L>>R;
		for(i=L;i<=R;i++)
		{
			if(binarySearch(perfect,i,0,perfect.size()-1))
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}

void populate()
{
	populatePrime();
	perfect = primes;
	long long len=primes.size(),temp,i,j;
	for(i=0;i<len;i++)
	{
		for(j=1;j<len;j++)
		{
			temp=primes[i]*primes[j];
			if(temp>1000000000000)
			{
				break;
			}
			perfect.push_back(temp);
		}
	}
	sort(perfect.begin(),perfect.end());
}

void populatePrime()
{
	long long i;
	for(i=2;i<=1000000000000;i++)
	{
		if(isPrime(i))
		{
			primes.push_back(i);
		}
	}
}

bool isPrime(long long num)
{
	bool ret=true;
	long long lim=(long long)floor(sqrt(num));
	long long count=0,i=0;
	for(i=2;i<=lim;i++)
	{
		if(num%i==0)
		{
			ret=false;
			break;
		}
	}
	return ret;
}

bool binarySearch(std::vector<long long>& v, const int& key, const long long& start, const long long& end)
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
			return true;
	}
}
