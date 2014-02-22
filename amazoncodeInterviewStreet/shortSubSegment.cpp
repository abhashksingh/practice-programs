#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

char easytolower(char in)
{
	if(in<='Z' && in>='A')
		return in-('Z'-'z');
	return in;
} 

vector <string> res;
map<string,bool> mapping;
map<string,int> mapping2;
void getResult(string inputArr[],string patternArr[],int inputArrSize,int patternArrSize);
bool allTrue(bool arr[],int arrSize);
void populateMapping(string patternArr[],int patternArrSize);
void printMinimum(string inputArr[],int* arr,int inputArrSize);

int main()
{
	locale loc;
	string text;
	getline(cin,text);
	int t,i;
	cin>>t;
	cin.ignore();
	string inp[t];
	for(i=0;i<t;i++)
	{
		getline(cin,inp[i]);
		transform(inp[i].begin(), inp[i].end(), inp[i].begin(), easytolower);
		//cout<<inp[i]<<endl;
	}
	//cout<<endl;
	text.erase(std::remove(text.begin(), text.end(), '.'), text.end());
	//tokenising the input text
	int spaceCount = 1+count(text.begin(), text.end(), ' ');
	string textArr[spaceCount];
	istringstream iss (text);
	for(i=0;i<spaceCount;i++)
	{
		iss >> textArr[i];
		transform(textArr[i].begin(), textArr[i].end(), textArr[i].begin(), easytolower);
	}
	//for(i=0;i<spaceCount;i++)
	//{
//		cout<<textArr[i]<<endl;
	//}
	//getResult(textArr,inp,spaceCount,t);
return 0;
}

bool allTrue(bool arr[],int arrSize)
{
	bool ret=true;
	for(int i=0;i<arrSize;i++)
	{
		if(arr[i]==false)
		{
			ret = false;
			break;
		}
	}
return ret;
}

void populateMapping(string patternArr[],int patternArrSize)
{
	for(int i=0;i<patternArrSize;i++)
	{
		mapping[patternArr[i]]=true;
		mapping2[patternArr[i]]=i;
	}
}

void getResult(string inputArr[],string patternArr[],int inputArrSize,int patternArrSize)
{
	populateMapping(patternArr,patternArrSize);
	int start,i,j;
	bool check[patternArrSize];
	int* patStart = new int[inputArrSize];
	for(start=0;start<inputArrSize-patternArrSize;start++)
	{
		memset(check,false,patternArrSize);
		for(i=start;i<inputArrSize;i++)
		{
			if(mapping[inputArr[i]])
			{
				check[mapping2[inputArr[i]]]=true;
				if(allTrue(check,patternArrSize))
				{
					patStart[start]=i-start+1;
					break;
				}
			}
		}
	}
	printMinimum(inputArr,patStart,inputArrSize);
}
void printMinimum(string inputArr[],int* arr,int inputArrSize)
{
	int min=INT_MAX,i,j,k;
	for(i=0;i<inputArrSize;i++)
	{
		if(min>arr[i])
		{
			min =arr[i];
			j=i;
		}
	}
	for(k=j;k<j+min;k++)
	{
		cout<<inputArr[k]<<" ";
	}
	cout<<endl;
}
