/*given a float convert it to string*/
#include <iostream>
#include <math.h>

#define lim 0.0000000000001
using namespace std;

string reverse(string input);
string myDtoA(double num);
string itoa(int num);

int main()
{
	double inp=-2.98;
	cout<<myDtoA(inp)<<endl;
}

string myDtoA(double num)
{
	if(num>0)
	{
		int inPart;
		double intPart,fractPart;
		fractPart = modf(num,&intPart);
		inPart=(int)intPart;
		string ret;
		ret = itoa(inPart);
		if(fractPart!=0)
		{
			ret.append(".");
			while(fractPart>lim)
			{
				double inP,fP;
				fractPart*=10;
				fP=modf(fractPart,&inP);
				int a =(int)inP;
				ret.append(itoa(a));
				fractPart=fP;
			}
		}
		else
		{ret.append(".0");}
		return ret;
	}
	else if(num==0)
	{
		return "0";
	}
	else if(num<0)
	{
		string ret = "-";
		ret.append(myDtoA(-num));
		return ret;
	}
}

string itoa(int num)
{
	if(num==0)
	{
		return "0";
	}
	char* str = new char[120];
	int i=0;
	// Process individual digits
	while (num != 0)
	{
		int rem = num % 10;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/10;
	}
	string ret(str);
	return reverse(ret);
}

/* A utility function to reverse a string  */
string reverse(string input)
{
	return std::string(input.rbegin(), input.rend());
}
