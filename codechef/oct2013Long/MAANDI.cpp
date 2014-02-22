#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<string> divisors;
void addDivisors(long long num);
long long countNearPerfects();
long long reverse(long long num);
string itoa(long long num);

int main()
{
	int t;
	long long num;
	cin>>t;
	while(t--)
	{
		cin>>num;
		divisors.clear();
		addDivisors(num);
		cout<<countNearPerfects()<<endl;
	}
}

void addDivisors(long long num)
{
	divisors.clear();
	long long i,t,lim=sqrt(num);
	divisors.push_back(itoa(num));
	for(i=1;i<=lim;i++)
	{
		if(num%i==0)
		{
			divisors.push_back(itoa(i));
			t=num/i;
			if(t!=i && t!=num)
			{
				divisors.push_back(itoa(t));
			}
		}
	}
}

long long countNearPerfects()
{
	long long i,siz=divisors.size(),count=0;
	for(i=0;i<siz;i++)
	{
		if(divisors[i].find('7') != std::string::npos || divisors[i].find('4')!= std::string::npos)
		{
			count++;
		}
	}
	return count;
}

long long reverse(long long num)
{
	long long rev=0;
	while(num>0)
	{
		rev=(rev*10)+(num%10);
		num=num/10;
	}
return rev;
}

string itoa(long long num)
{
	string ret= "";
	long long rev=reverse(num),temp=0;
	while(rev>0)
	{
		temp=rev%10;
		rev=rev/10;
		switch(temp)
		{
			case 0:
				ret+="0";
				break;
			case 1:
				ret+="1";
				break;
			case 2:
				ret+="2";
				break;
			case 3:
				ret+="3";
				break;
			case 4:
				ret+="4";
				break;
			case 5:
				ret+="5";
				break;
			case 6:
				ret+="6";
				break;
			case 7:
				ret+="7";
				break;
			case 8:
				ret+="8";
				break;
			case 9:
				ret+="9";
				break;
		}
	}
	//cout<<ret<<endl;
	return ret;
}
