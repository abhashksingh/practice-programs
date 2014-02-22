#include <iostream>
#include <stdio.h>
#include <string>
#include <stdint.h>
using namespace std;

bool test_input(int test_num);
bool balencedornot(string ip);
bool balenced_with_colon(string ip);
bool balenced_with_smileys(string ip);
bool contains_alphabets(string ip);
bool is_alphabet(char a);
string remove_substr(string ip,string sub);

int main()
{
	int num_test;
	cin>>num_test;
	if(test_input(num_test))
	{
		string inp[num_test];
		string res;
		bool val=false;
		char c;
		scanf("%c",&c);
		for(int i=0;i<num_test;i++)
		{
			getline(cin,inp[i]);
		}
		for(int i=0;i<num_test;i++)
		{
			if(inp[i].length()>=1 && inp[i].length()<=100)
			{
				val=balencedornot(inp[i]);
				if(val)
				{
					res="YES";
				}
				else
				{
					res="NO";
				}
			}
			cout<<"Case #"<<i+1<<": "<<res<<endl;
		}
	}
}

bool balencedornot(string ip)
{
	bool val1 = contains_alphabets(ip);
	bool val2 = balenced_with_colon(ip);
	bool val3 = balenced_with_smileys(ip);
	bool ret = ((val1)&&(val2||val3));
	return ret;
	}

string remove_substr(string ip,string sub)
{
	int pos;
	pos=ip.find(sub);
	int len=sub.length();
	while(pos>=0)
	{
		ip.erase(pos,len);
		pos=ip.find(sub);
	}
	return ip;
}

bool balenced_with_colon(string ip)
{
	string inp=remove_substr(ip,":");
	int count=0,pos=-1;
	for(int i=0;i<inp.length();i++)
	{
		if(inp[i]=='(')
		{
			pos=i;
			count++;
		}
		else if(inp[i]==')' && pos>=0 && i>pos)
		{
			count--;
		}
	}
	if(count==0)
		return true;
	else
		return false;
}

bool balenced_with_smileys(string ip)
{
	bool ret = false;
	string inp;
	uint32_t p1=ip.find(":)"),p2=ip.find(":(");
	if(p1!=string::npos || p2!=string::npos)
	{
		if(p1!=string::npos)
		{
			inp=remove_substr(ip,":)");
		}
		if(p2!=string::npos)
		{
			inp=remove_substr(ip,":(");
		}
		int count=0,pos=-1;
		for(int i=0;i<inp.length();i++)
		{
			if(inp[i]=='(')
			{
				pos=i;
				count++;
			}
			else if(inp[i]==')' && pos>=0 && i>pos)
			{
				count--;
			}
		}
		if(count==0)
			ret=true;
		else
			ret= false;
	}
	else
	{
		ret=false;
	}
	return ret;
}

bool contains_alphabets(string ip)
{
	bool val=false;
	if(ip.empty())
	{
		val=true;
	}
	else
	{
		for(int i=0;i<ip.length();i++)
		{
			if(is_alphabet(ip[i]))
			{
				val=true;
				break;
			}
		}
	}
	return val;
}

bool is_alphabet(char a)
{
	bool val=false;
	switch(a)
	{
		case 'a':
		case 'A':
		val=true;
		break;
		case 'b':
		case 'B':
		val=true;
		break;
		case 'c':
		case 'C':
		val=true;
		break;
		case 'd':
		case 'D':
		val=true;
		break;
		case 'e':
		case 'E':
		val=true;
		break;
		case 'f':
		case 'F':
		val=true;
		break;
		case 'g':
		case 'G':
		val=true;
		break;
		case 'h':
		case 'H':
		val=true;
		break;
		case 'i':
		case 'I':
		val=true;
		break;
		case 'j':
		case 'J':
		val=true;
		break;
		case 'k':
		case 'K':
		val=true;
		break;
		case 'l':
		case 'L':
		val=true;
		break;
		case 'm':
		case 'M':
		val=true;
		break;
		case 'n':
		case 'N':
		val=true;
		break;
		case 'o':
		case 'O':
		val=true;
		break;
		case 'p':
		case 'P':
		val=true;
		break;
		case 'q':
		case 'Q':
		val=true;
		break;
		case 'r':
		case 'R':
		val=true;
		break;
		case 's':
		case 'S':
		val=true;
		break;
		case 't':
		case 'T':
		val=true;
		break;
		case 'u':
		case 'U':
		val=true;
		break;
		case 'v':
		case 'V':
		val=true;
		break;
		case 'w':
		case 'W':
		val=true;
		break;
		case 'x':
		case 'X':
		val=true;
		break;
		case 'y':
		case 'Y':
		val=true;
		break;
		case 'z':
		case 'Z':
		val=true;
		break;
		case ' ':
		val=true;
		break;
		case ':':
		val=true;
		break;
		default :
		val=false;
	}
	return val;
}

bool test_input(int test_num)
{
	if(test_num>=1 && test_num<=50)
	{
		return true;
	}
	return false;
}
