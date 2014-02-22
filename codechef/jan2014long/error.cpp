#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	string inp,c1="010",c2="101";
	long long t;
	size_t r1,r2;
	scanf("%lld",&t);
	cin.ignore();
	while(t--)
	{
		getline(cin,inp);
		r1 = inp.find(c1);
		r2 = inp.find(c2);
		if((r1!=string::npos)&&(r2!=string::npos))
		{
			printf("%s","Good\n");
		}
		else
		{
			printf("%s","Bad\n");
		}
	}
}
