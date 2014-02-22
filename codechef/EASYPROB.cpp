

#include <iostream>
#include <fstream>
using namespace std;
/*
* String Uses a Recursive Function to Achieve the Effect.
*/
string ret(int a)
{
	/*
	* Base Cases 
	*/
	if (a <= 0)
		return "";
	else if (a == 1)
		return "2(0)";
	else if (a == 2)
		return "2";
	/*
	*  Recursive Step Begins here.
	*/

	else {
		string s = "";
		int count = 1;
		while (a > 0) {
			if (a % 2 == 1)
				//Magic Statement
				s = (count <= 2 ? ret(count) : "2(" + ret(count - 1) + ")")+(s == "" ? "" : "+") + s;
				count++;
				a /= 2;
		}
		return s;
	}
}

int main()
{
	int a;
	while (cin >> a)
	{
		cout << a << "=" << ret(a) << endl;
	}
return 0;
}
