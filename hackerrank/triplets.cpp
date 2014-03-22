#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

//dscArray is the first appearance index
vector<long long> lSmaller,rLarger,treeArray,dscArray,lFlags,rFlags;
long long size,countU=0;


void InitialiseAllArrays(vector<long long> inputArr,long long aSize);
void update(long long idx);
void countLeftSmaller();
void countRightLarger();
long long read(long long index);
long long countTriplets();
int main()
{
	long long N,i,t;
	vector<long long> arr;
	cin>>N;
	arr.resize(N);
	for(i=0;i<N;i++)
	{
		cin>>t;
		arr[i]=t;
	}
	InitialiseAllArrays(arr,N);
	countLeftSmaller();
	countRightLarger();
	cout<<countTriplets()<<endl;
}


void InitialiseAllArrays(vector<long long> inputArr,long long aSize)
{
	size = aSize;
	lSmaller.resize(size);
	rLarger.resize(size);
	dscArray.resize(size);
	vector<long long> tempArray = inputArr;
	sort(tempArray.begin(),tempArray.end());
	map<long long,long long> tmpMap;
	for(long long i=0;i<size;i++)
	{
		map<long long,long long>::iterator it = tmpMap.find(tempArray[i]);
		if(it==tmpMap.end())
		{
			countU++;
			tmpMap.insert(pair<long long,long long>(tempArray[i],countU));
		}
	}
	countU++;
	treeArray.resize(countU);
	lFlags.resize(countU);
	rFlags.resize(countU);
	for(long long i=0;i<size;i++)
	{
		dscArray[i]=tmpMap[inputArr[i]];
	}
}

void update(long long idx)
{
	while (idx < countU)
	{
		treeArray[idx]++;
		idx += (idx & -idx);
	}
}

long long read(long long index)
{
	long long sum = 0;
	while (index > 0)
	{
		sum += treeArray[index];
		index -= (index & -index);
	}
return sum;
}

void countLeftSmaller()
{
	treeArray.assign(countU,0);
	lSmaller.assign(countU,0);
	lFlags.assign(countU,0);
	for(long long i = 0; i < size; i++)
	{
		long long val = dscArray[i];
		lSmaller[i] = read(val - 1);
		if (lFlags[val] == 0)
		{
			update(val);
			lFlags[val] = i + 1;
		}
		else
		{
			lSmaller[i] -= lSmaller[lFlags[val] - 1];
		}
	}
}

void countRightLarger()
{
	treeArray.assign(countU,0);
	rLarger.assign(countU,0);
	rFlags.assign(countU,0);
	for(long long i = size - 1; i >= 0; i--)
	{
		int val = dscArray[i];
		rLarger[i] = read(countU - 1) - read(val);
		if (rFlags[val] == 0)
		{
			update(val);
			rFlags[val] = i + 1;
		}
	}
}

long long countTriplets()
{
	long sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += lSmaller[i] * rLarger[i];
	}
	return sum;
}
