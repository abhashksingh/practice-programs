#include <stdlib.h>
#include <boost/regex.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost;

void process(string inp);

int main()
{
	string inp;
	int test;
	cin>>test;
	//cout<<test<<endl;
	cin.ignore();
	while(test--)
	{
		getline(cin,inp);
		process(inp);
	}
return 0;
}

void process(string inp)
{
	string panex= "[A-Z]{5}\\d{4}[A-Z]{1}";
	regex paneg(panex);
	cmatch what;
	regex_match(inp.c_str(),what,paneg);
	if(what[0].matched)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
//any difficulty while compiling this program
//go to http://fenikslied.blogspot.in/2010/02/installung-boost-regex-library-on.html
