#include <iostream>
#include <string>
#include <climits> // for throwing INT_MIN when input is not valid

using namespace std;

bool isValidChar(char a)
{
	
	if(a=='-')
	{
		return true;
	}
	else if(a=='1')
	{
		return true;
	}
	else if(a=='2')
	{
		return true;
	}
	else if(a=='3')
	{
		return true;
	}
	else if(a=='4')
	{
		return true;
	}
	else if(a=='5')
	{
		return true;
	}
	else if(a=='6')
	{
		return true;
	}
	else if(a=='7')
	{
		return true;
	}
	else if(a=='8')
	{
		return true;
	}
	else if(a=='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int strToInt(string s)
{
    int t=1,ret=0,start=0;
    bool fneg=false;//to make sure that - appears only in begining
    if(s[0]=='-')
    {
        t*=-1;
        start=1;
        fneg = true;
    }
    for(int i=start;i<s.length() -1;i++)
    {
        if(isValidChar(s[i])&& !fneg)
        {
            ret=ret*10+(s[i])-48;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            return INT_MIN;
        }
    }
    return t*ret;
}

int main(){}
