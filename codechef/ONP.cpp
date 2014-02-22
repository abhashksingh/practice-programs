#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

stack <char> mystack;

int main ()
{
	int total;
	cin >> total;
	cin.ignore();
	while (total-- > 0)
	{
		string inp,ret="";
		getline(cin,inp);
		for (int i = 0; i < inp.length(); i++)
		{
			if (inp[i] >= 'a' && inp[i] <= 'z')
			{
				ret+=inp[i];
			}
			else if (inp[i] == ')')
			{
				while (mystack.top() != '(')
				{
					ret+=mystack.top();
					mystack.pop();
				}
				mystack.pop();
			}
			else
			{
				mystack.push (inp[i]);
			}
		}
		while (!mystack.empty())
		{
			ret+=mystack.top();
			mystack.pop();
		}
		cout<<ret<<endl;
	}
	return 0;
}
