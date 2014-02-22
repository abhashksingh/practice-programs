#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;
int findSize(string inp);

int main()
{
	int N,index=0,i=0;
	cin>>N;
	char c;
	scanf("%c",&c);
	for(i=0;i<N;i++)
	{
		string inp;
		getline(cin,inp);
		int size=findSize(inp);
		if(size==1)
		{
			cout<<"Case #"<<i+1<<": "<<inp<<endl;
		}
		else
		{
			vector<string> toke;
			tokenizer<> tok(inp);
			for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg)
			{
				toke.push_back(*beg);
			}
			typedef vector<string>::iterator iter_int;
			iter_int begin (toke.begin());
			iter_int end (toke.end());
			reverse_iterator<iter_int> rev_end (begin);
			reverse_iterator<iter_int> rev_iterator (end);
			cout<<"Case #"<<i+1<<": ";
			while (rev_iterator < rev_end)
			{
				cout<< *rev_iterator++ << " ";
			}
			cout<<endl;
		}
		
	}
}

int findSize(string inp)
{
	int num_space=0;
	for(int i=0;i<inp.length();i++)
	{
		if(inp.at(i)==' ')
		{
			num_space++;
		}
	}
return num_space+1;
}
