/*Write a method to compute all permutations of a string*/
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

string insertCharAt(string word,char c,int i);
vector<string> getPermutation(string inp);

int main()
{
	string inp;
	char c;
	getline(cin,inp);
	cout<<inp<<endl<<endl;
	//scanf("%c",&c);
	vector <string> per=getPermutation(inp);
	vector<string>::const_iterator it;
	for(it=per.begin();it!=per.end();it++)
	{
		cout<<*it<<endl;
	}
return 0;
}

vector<string> getPermutation(string inp)
{
	//cout<<inp<<endl;
	vector<string> permutations;
	if(inp.length()==0)
	{
		permutations.push_back("");
		return permutations;
	}
	else
	{
		//cout<<inp<<endl;
		char first=inp.at(0);
		string remainder=inp.substr(1);
		vector<string>::const_iterator it;
		vector<string> words = getPermutation(remainder);
		for(it=words.begin();it!=words.end();it++)
		{
			string word=*it;
			for(int j=0;j<word.length();j++)
			{
				string s;
				s=insertCharAt(word,first,j);
				
				permutations.push_back(s);
			}
		}
	}
}
string insertCharAt(string word,char c,int i)
{
	string start=word.substr(0,i);
	string end=word.substr(i);
	return start+c+end;
}
