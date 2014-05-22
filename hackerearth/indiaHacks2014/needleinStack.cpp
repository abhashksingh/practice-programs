#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <limits.h>

using namespace std;

map<char, long long > mapping;

void populateMapping();
void populateArray(long long  **ar,string inp);
bool compareArrays(long long * arr1,long long * arr2);
bool minWindow(const char* S, const char *T,long long &minWindowBegin, long long &minWindowEnd);

int main()
{
	populateMapping();
	long long t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		long long  *arr1 = new long long [26];
		long long  *arr2 = new long long [26];
		for(long long  i=0;i<26;i++)
		{
			arr1[i]=0;arr2[i]=0;
		}
		string str1,str2;
		getline(cin,str1);
		getline(cin,str2);
		if(str1.empty()||str2.empty())
		{
			cout<<"NO"<<endl;
		}
		else
		{
			long long  len1=str1.length();
			long long  len2=str2.length();
			
			if(len1>len2)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				long long begin,end;
				if(minWindow(str2.c_str(),str1.c_str(),begin,end))
				{
					string resStr(str2.begin()+begin,str2.begin()+end+1);
					populateArray(&arr1,str1);
					populateArray(&arr2,resStr);
					if(compareArrays(arr1,arr2))
					{cout<<"YES"<<endl;}
					else
					{cout<<"NO"<<endl;}
				}
				else
				{cout<<"NO"<<endl;}
			}
			str1="";
			str2="";
		}
	}
}

void populateArray(long long  **ar,string inp)
{
	long long  len = inp.length(),i=0;
	long long * arr = *ar;
	for(i=0;i<len;i++)
	{
		arr[mapping[inp[i]]]++;
	}
}

bool compareArrays(long long * arr1,long long * arr2)
{
	//long long * ar1=*arr1;
	//long long * ar2=*arr2;
	bool ret = true;
	for(long long  i=0;i<26;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

void populateMapping()
{
	mapping.insert(pair<char,long long >('a',0));
	mapping.insert( pair<char,long long >('b',1));
	mapping.insert( pair<char,long long >('c',2));
	mapping.insert( pair<char,long long >('d',3));
	mapping.insert( pair<char,long long >('e',4));
	mapping.insert( pair<char,long long >('f',5));
	mapping.insert( pair<char,long long >('g',6));
	mapping.insert( pair<char,long long >('h',7));
	mapping.insert( pair<char,long long >('i',8));
	mapping.insert( pair<char,long long >('j',9));
	mapping.insert( pair<char,long long >('k',10));
	mapping.insert( pair<char,long long >('l',11));
	mapping.insert( pair<char,long long >('m',12));
	mapping.insert( pair<char,long long >('n',13));
	mapping.insert( pair<char,long long >('o',14));
	mapping.insert( pair<char,long long >('p',15));
	mapping.insert( pair<char,long long >('q',16));
	mapping.insert( pair<char,long long >('r',17));
	mapping.insert( pair<char,long long >('s',18));
	mapping.insert( pair<char,long long >('t',19));
	mapping.insert( pair<char,long long >('u',20));
	mapping.insert( pair<char,long long >('v',21));
	mapping.insert( pair<char,long long >('w',22));
	mapping.insert( pair<char,long long >('x',23));
	mapping.insert( pair<char,long long >('y',24));
	mapping.insert( pair<char,long long >('z',25));
}

// Returns false if no valid window is found. Else returns 
// true and updates minWindowBegin and minWindowEnd with the 
// starting and ending position of the minimum window.
bool minWindow(const char* S, const char *T,long long &minWindowBegin, long long &minWindowEnd)
{
	int sLen = strlen(S);
	int tLen = strlen(T);
	int needToFind[256] = {0};

	for (int i = 0; i < tLen; i++)
		needToFind[T[i]]++;

	int hasFound[256] = {0};
	int minWindowLen = INT_MAX;
	int count = 0;
	for (int begin = 0, end = 0; end < sLen; end++)
	{
		// skip characters not in T
		if (needToFind[S[end]] == 0) continue;
			hasFound[S[end]]++;
		if (hasFound[S[end]] <= needToFind[S[end]])
			count++;

		// if window constraint is satisfied
		if (count == tLen)
		{
			// advance begin index as far right as possible,
			// stop when advancing breaks window constraint.
			while (needToFind[S[begin]] == 0 ||hasFound[S[begin]] > needToFind[S[begin]])
			{
				if (hasFound[S[begin]] > needToFind[S[begin]])
					hasFound[S[begin]]--;
				begin++;
			}

			// update minWindow if a minimum length is met
			int windowLen = end - begin + 1;
			if (windowLen < minWindowLen)
			{
				minWindowBegin = begin;
				minWindowEnd = end;
				minWindowLen = windowLen;
			} // end if
		} // end if
	} // end for

return (count == tLen) ? true : false;
}
