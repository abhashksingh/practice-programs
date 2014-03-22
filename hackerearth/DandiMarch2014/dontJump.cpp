#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
	long long N;
	cin>>N;
	cin.ignore();
	string inp;
	bool arr[N];
	for(long long i =0;i<N;i++)
	{
		arr[i]= false;
	}
	while(getline(cin,inp))
	{
		if(inp.empty())
		{
			cout<<0<<endl;
		}
		else
		{
			string ret="";
			long long num,lastTrue=-1;
			char input[101];
			strcpy (input, inp.c_str());
			while(sscanf(input,"%lld",&num))
			{
				if(num<lastTrue)
				{
					while(num>lastTrue)
					{
						ret+='C';
						lastTrue++;
						arr[lastTrue]= true;
					}
					ret+='K';
				}
				else if(num==lastTrue)
				{
					ret+='K';
					arr[lastTrue]=false;
					lastTrue--;
				}
				else
				{
					while(num<lastTrue)
					{
						ret+='K';
						arr[lastTrue]=false;
						lastTrue--;
					}
				}
			}
			cout<<ret<<endl;
		}
	}
}
