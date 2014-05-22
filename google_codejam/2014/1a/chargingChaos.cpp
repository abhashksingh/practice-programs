#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <map>

using namespace std;

bool compareStringArrays(vector<string> &A,vector<string> &B);
string StringXOR(string &A,string &B);
vector<string> IntersectionOfMapping(map< string , map<string,string> > &mapping);
vector<string> IntersectionOfStringArrays(vector<string>& A,vector<string>& B);
int numberOfDifferentBits(string &A,string &B);
int countNumberOf1s(string inp);

int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		string tempStr;
		vector<string> device,supply;
		int N,L,j=0;
		cin>>N>>L;
		cin.ignore();
		for(j=0;j<N;j++)
		{
			cin>>tempStr;
			device.push_back(tempStr);
		}
		for(j=0;j<N;j++)
		{
			cin>>tempStr;
			supply.push_back(tempStr);
		}
		if(N==1)
		{
			cout<<numberOfDifferentBits(device[0],supply[0])<<endl;
		}
		else
		{
			sort(device.begin(),device.end());
			sort(supply.begin(),supply.end());
			if(compareStringArrays(device,supply))
			{cout<<0<<endl;}
			else
			{
				map< string , map<string,string> > mapping;
				int size = device.size(),k=0;
				for(j=0;j<size;j++)
				{
					for(k=0;k<size;k++)
					{
						mapping[device[j]][supply[k]]= StringXOR(device[j],supply[k]);
					}
				}
				vector<string> intersection = IntersectionOfMapping(mapping);
				if(intersection.size()==0){cout<<"NOT POSSIBLE"<<endl;}
				else if(intersection.size()==1)
				{
					cout<<countNumberOf1s(intersection[0])<<endl;
				}
				else
				{
					//cout<<"More than 1 plz wait"<<endl;
					int min=countNumberOf1s(intersection[0]),tmin;
					for(int y = 1 ;y< intersection.size();y++)
					{
						tmin = countNumberOf1s(intersection[y]);
						if(min>tmin) min=tmin;
					}
					cout<<min<<endl;
				}
			}
		}
	}
}


bool compareStringArrays(vector<string> &A,vector<string> &B)
{
	bool ret=true;
	int size = A.size(),i=0;
	for(i=0;i<size;i++)
	{
		if(A[i].compare(B[i])!=0)
		{
			ret =false;
			break;
		}
	}
return ret;
}


string StringXOR(string &A,string &B)
{
	string res="";
	int size = A.size(),i=0;
	for(i=0;i<size;i++)
	{
		if(A[i]==B[i])
		{res+='0';}
		else {res+='1';}
	}
	return res;
}

vector<string> IntersectionOfMapping(map< string , map<string,string> > &mapping)
{
	//first transform map to a 2d vector
	vector<string> temp,res;
	vector< vector<string> > vectorMap;
	map<string,string>::iterator tempIt;
	map< string , map<string,string> >::iterator it = mapping.begin();
	while(it!=mapping.end())
	{
		temp.clear();
		tempIt = it->second.begin();
		while(tempIt!= it->second.end())
		{
			temp.push_back(tempIt->second);
			tempIt++;
		}
		sort(temp.begin(),temp.end());
		vectorMap.push_back(temp);
		it++;
	}
	int siz = vectorMap.size();
	res = IntersectionOfStringArrays(vectorMap[0],vectorMap[1]);
	for(int d = 2;d<siz;d++)
	{
		res = IntersectionOfStringArrays(res,vectorMap[d]);
	}
	return res;
}

vector<string> IntersectionOfStringArrays(vector<string>& A,vector<string>& B)
{
	int i=0,j=0,m=A.size(),n=B.size();
	map<string,int>uniqC;
	vector<string> res;
	for(int i=0;i<m;i++)
	{
		map<string,int>::iterator it = uniqC.find(A[i]);
		if(it!=uniqC.end())
		{
			uniqC[A[i]]++;
		}
		else
		{
			uniqC[A[i]]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		map<string,int>::iterator it = uniqC.find(B[i]);
		if(it!=uniqC.end())
		{
			uniqC[B[i]]++;
		}
		else
		{
			uniqC[B[i]]=1;
		}
	}
	
	map<string,int>::iterator it = uniqC.begin();
	while(it!=uniqC.end())
	{
		if(it->second > 1)
		{
			res.push_back(it->first);
		}
		it++;
	}
	return res;
}

int numberOfDifferentBits(string &A,string &B)
{
	int len = A.size(),i=0,ret=0;
	for(i=0;i<len;i++)
	{
		if(A[i]!=B[i]){ret++;}
	}
	return ret;
}


int countNumberOf1s(string inp)
{
	int ret =0;
	for(int i=0;i<inp.size();i++)
	{
		if(inp[i]=='1')
		{ret++;}
	}
	return ret;
}
