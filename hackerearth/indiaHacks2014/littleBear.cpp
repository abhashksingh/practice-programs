#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void populateVectors(const std::string& referenceString, const std::string& subString,bool t1);
void populateUniquMap(string& referenceString,string& prefix,string& suffix);//first t2 greater than t1[0]
vector <size_t>t1Occur,t2Occur;
map<string,int> uniq;
int main()
{
	int i=0;
	string S,T1,T2;
	while(getline(cin,S)&&getline(cin,T1)&&getline(cin,T2))
	{
		if(!t1Occur.empty()){t1Occur.clear();}
		if(!t2Occur.empty()){t2Occur.clear();}
		if(!uniq.empty()){uniq.clear();}
		populateVectors(S,T1,true);
		populateVectors(S,T2,false);
		if(t1Occur.empty()||t2Occur.empty())
		{cout<<0<<endl;}
		else
		{
			populateUniquMap(S,T1,T2);
			cout<<uniq.size()<<endl;
			//cout<<subC-findAppropiateLocation()<<endl;
		}
	}
}

void populateVectors(const std::string& referenceString, const std::string& subString,bool t1)
{

	const size_t step = subString.size();
	//size_t count(0);
	size_t pos(0) ;

	while( (pos=referenceString.find(subString, pos)) !=std::string::npos)
	{
		if(t1)
		{t1Occur.push_back(pos);}
		else
		{t2Occur.push_back(pos);}
		pos++;
		//++count ;
	}
//return count;
}

void populateUniquMap(string& referenceString,string& prefix,string& suffix)
{
	//bool bre=false;
	vector<size_t> :: iterator it1 = t1Occur.begin(),v1end=t1Occur.end();
	vector<size_t> :: iterator it2 = t2Occur.begin(),v2end=t2Occur.end(),it2beg=it2;
	if(t1Occur[0]>=t2Occur.back()){return;}
	for(;it1!=v1end;it1++)
	{
		for(it2 = it2beg;it2!=v2end;it2++)
		{
			if(*it2<=*it1){continue;}
			string str(referenceString.begin()+(*it1),referenceString.begin()+(*it2)+suffix.length());
			map<string,int> :: iterator it = uniq.find(str);
			if(it==uniq.end()){uniq.insert(pair<string,int>(str,1));}
		}
	}
}

long long findHigherPrime(size_t key)
{
	int low =0,high = t2Occur.size();
	while (low <= high)
	{
		int mid = low+ (high- low) / 2; // Or a fancy way to avoid int overflow
		if (t2Occur[mid] <=  key)
		{
			/* This index, and everything below it, must not be the first element
			* greater than what we're looking for because this element is no greater
			* than the element.
			*/
			low = mid + 1;
		}
		else
		{
			vector<size_t>::iterator nth = t2Occur.begin() + mid;
			return nth;
		}
	}
	//return t2Occur.end();
}
