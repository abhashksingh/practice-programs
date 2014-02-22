#include <iostream>
#include <string>

using namespace std;

int holes(string inp);

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string inp;
		getline(cin,inp);
		cout<<holes(inp)<<endl;
	}
return 0;
}

int holes(string inp)
{
	int length=inp.size();
	int ret=0,i=0;
	for(i=0;i<length;i++)
	{
		char ch=inp[i];
		switch(ch)
		{
			case 'B':
				ret+=2;
				break;
			case 'A':
			case 'D':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
				ret+=1;
				break;
			default:
				ret+=0;
		}
	}
	return ret;
}
