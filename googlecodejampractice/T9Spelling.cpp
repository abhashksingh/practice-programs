#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;
map<char,int> mapping;
map<char,int> key;
void populate_mapping();
bool pause_required(string inp,int pos);

int main()
{
	populate_mapping();
	int N,index=0,i=0;
	cin>>N;
	char c;
	scanf("%c",&c);
	for(i=0;i<N;i++)
	{
		string inp;
		getline(cin,inp);
		cout<<"Case #"<<i+1<<": ";
		for(index=0;index<inp.length();index++)
		{
			if(pause_required(inp,index))
			{
				cout<<" ";
			}
			cout<<mapping[inp.at(index)];
		}
		cout<<endl;
	}
}

void populate_mapping()
{
	mapping[' ']=0;
	mapping['a']=2;
	mapping['b']=22;
	mapping['c']=222;
	mapping['d']=3;
	mapping['e']=33;
	mapping['f']=333;
	mapping['g']=4;
	mapping['h']=44;
	mapping['i']=444;
	mapping['j']=5;
	mapping['k']=55;
	mapping['l']=555;
	mapping['m']=6;
	mapping['n']=66;
	mapping['o']=666;
	mapping['p']=7;
	mapping['q']=77;
	mapping['r']=777;
	mapping['s']=7777;
	mapping['t']=8;
	mapping['u']=88;
	mapping['v']=888;
	mapping['w']=9;
	mapping['x']=99;
	mapping['y']=999;
	mapping['z']=9999;

	key[' ']=0;
	key['a']=2;
	key['b']=2;
	key['c']=2;
	key['d']=3;
	key['e']=3;
	key['f']=3;
	key['g']=4;
	key['h']=4;
	key['i']=4;
	key['j']=5;
	key['k']=5;
	key['l']=5;
	key['m']=6;
	key['n']=6;
	key['o']=6;
	key['p']=7;
	key['q']=7;
	key['r']=7;
	key['s']=7;
	key['t']=8;
	key['u']=8;
	key['v']=8;
	key['w']=9;
	key['x']=9;
	key['y']=9;
	key['z']=9;
}

bool pause_required(string inp,int pos)
{
	if((pos>0)&&(key[inp.at(pos-1)]==key[inp.at(pos)]))
	{
		return true;
	}
	return false;
}
