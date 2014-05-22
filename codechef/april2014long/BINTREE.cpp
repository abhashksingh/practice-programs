#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

vector <long long> lcai,lcaj;
void populateVector(long long i,bool iarr);
vector<long long> intersection();
void populateLog();

vector<long long> lgb2;

int main()
{
	long long t,i,j;
	cin>>t;
	while(t--)
	{
		if(!lcai.empty()){lcai.clear();}
		if(!lcaj.empty()){lcaj.clear();}
		cin>>i>>j;
		populateVector(i,true);
		populateVector(j,false);
		sort(lcai.begin(),lcai.end());
		sort(lcaj.begin(),lcaj.end());
		vector <long long> lcaArr = intersection();
		long long lca = lcaArr[lcaArr.size()-1],pow2i=0,pow2j=0,pow2l=0;
		pow2i=(long long)floor(log(i)/log(2));
		pow2j=(long long)floor(log(j)/log(2));;
		pow2l=(long long)floor(log(lca)/log(2));;
		cout<<pow2i+pow2j-(pow2l*2)<<endl;
	}
}

void populateVector(long long i,bool arri)
{
	if(arri)
	{
		while(i>0)
		{
			lcai.push_back(i);
			i = i>>1;
		}
	}
	else
	{
		while(i>0)
		{
			lcaj.push_back(i);
			i = i>>1;
		}
	}
}

vector<long long> intersection()
{
	vector<long long> ret;
	long long m=lcai.size(),n=lcaj.size(),i=0,j=0;
	while(i < m && j < n)
	{
		if(lcai[i] < lcaj[j])
			i++;
		else if(lcaj[j] < lcai[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			ret.push_back(lcaj[j++]);
			//printf(" %d ", arr2[j++]);
			i++;
		}
	}
	return ret;
}

void populateLog()
{
	//lgb2.reserve(1000000001);
	lgb2.push_back(0);//log 0 = 0 just a hypothessis
	lgb2.push_back(0);//log 1 = 0 this is trues
	for(long long i=2;i<1000000001;i++)
	{
		lgb2.push_back(lgb2[i>>1]+1);
	}
}
