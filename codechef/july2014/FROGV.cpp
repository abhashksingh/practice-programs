#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Frog
{
	public :
		long long index;
		long long position;
		long long maxreach;
		Frog(long long i,long long pos)
		{
			index = i;
			position = pos;
			maxreach = 0;
		}
};

bool CompareByPos(Frog a ,Frog b)
{
	return (a.position < b.position);
}

bool CompareByIndex(Frog a ,Frog b)
{
	return (a.index < b.index);
}

void swap(long long* a,long long* b)
{
	long long i=90;
	long long* c = &i;
	*c = *b;
	*b = *a;
	*a = *b;
}

int main()
{
	vector<Frog> frog;
	long long n,k,p,i=0;
	cin>>n>>k>>p;
	long long* arr = new long long[n];// the initial position of frogs
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		Frog a(i,arr[i]);
		frog.push_back(a);
	}
	sort(frog.begin(),frog.end(),CompareByPos);
	frog[n-1].maxreach = frog[n-1].position +k;

	for(i=n-2;i>=0;i--)
	{
		if(frog[i].position + k >= frog[i+1].position)
		{
			frog[i].maxreach = frog[i+1].maxreach;
		}
		else
		{
			frog[i].maxreach = frog[i].position + k;
		}
	}
	sort(frog.begin(),frog.end(),CompareByIndex);
	long long x,y;
	for(i=0;i<p;i++)
	{
		cin>>x>>y;
		if(x>y) swap(&x,&y);//swapping if message needs to be transmitted backwards
		if(frog[x-1].maxreach > frog[y-1].position)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
