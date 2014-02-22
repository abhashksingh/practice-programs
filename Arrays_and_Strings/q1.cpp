/*Implement an algorithm to determine if a string has all unique characters*/


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool checkStr(string str);
int main(int argc, char **argv)
{
	cout<<"Enter an String "<<endl;
	string str;
	getline(cin,str);
	bool chk=checkStr(str);
	cout<<chk<<endl;
	return 0;
}

bool checkStr(string str)
{
	//cout<<str<<endl;
	if(str.length()>256){
		return false;
		}
	bool char_set[256];
	for(int i=0;i<256;i++)
	{
		char_set[i]=false;
	}
	for(int i=0;i<str.length();i++)
	{
		int val=str[i];
		if(char_set[val])
		{
			return false;
			}
		char_set[val]=true;
	}
		return true;
}

