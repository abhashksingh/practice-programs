#include <iostream>
using namespace std;
bool test_input(int num_tests);
int beauty(string ip);
int calc_val(char a);
int main()
{
	int num_tests;
	cin>>num_tests;
	if(test_input(num_tests))
	{
		string inp[num_tests];
		for(int i=0;i<num_tests;i++)
		{
			cout<<"i+1 : ";
			getline(cin,inp[i]);
		}
		for(int i=0;i<num_tests;i++)
		{
			cout<<"Case #"<<i+1<<":"<<beauty(inp[i])<<endl;
		}
	}
}

bool test_input(int num_tests)
{
	if(num_tests>=5 && num_tests<=50)
	{
		return true;
	}
	return false;
}

int beauty(string ip)
{
	int val=0;
	if(ip.length()>=2 && ip.length() <=50)
	{
		for(int i=0;i<ip.length();i++)
		{
			val+=calc_val(ip[i]);
		}
	}
	return val;
}

int calc_val(char a)
{
	int val=0;
	switch(a)
	{
		case 'a':
		case 'A':
		val=1;
		break;
		case 'b':
		case 'B':
		val=2;
		break;
		case 'c':
		case 'C':
		val=3;
		break;
		case 'd':
		case 'D':
		val=4;
		break;
		case 'e':
		case 'E':
		val=5;
		break;
		case 'f':
		case 'F':
		val=6;
		break;
		case 'g':
		case 'G':
		val=7;
		break;
		case 'h':
		case 'H':
		val=8;
		break;
		case 'i':
		case 'I':
		val=9;
		break;
		case 'j':
		case 'J':
		val=10;
		break;
		case 'k':
		case 'K':
		val=11;
		break;
		case 'l':
		case 'L':
		val=12;
		break;
		case 'm':
		case 'M':
		val=13;
		break;
		case 'n':
		case 'N':
		val=14;
		break;
		case 'o':
		case 'O':
		val=15;
		break;
		case 'p':
		case 'P':
		val=16;
		break;
		case 'q':
		case 'Q':
		val=17;
		break;
		case 'r':
		case 'R':
		val=18;
		break;
		case 's':
		case 'S':
		val=19;
		break;
		case 't':
		case 'T':
		val=20;
		break;
		case 'u':
		case 'U':
		val=21;
		break;
		case 'v':
		case 'V':
		val=22;
		break;
		case 'w':
		case 'W':
		val=23;
		break;
		case 'x':
		case 'X':
		val=24;
		break;
		case 'y':
		case 'Y':
		val=25;
		break;
		case 'z':
		case 'Z':
		val=26;
		break;
		default :
		val=0;
	}
	return val;
}
