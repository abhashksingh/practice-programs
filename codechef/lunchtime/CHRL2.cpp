#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int c=0,h=0,e=0,f=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='C')
			c++;
		else if(s[i]=='H')
		{
			if(c>0)
			{
				c--;h++;
			}
		}
		else if(s[i]=='E')
		{
			if(h>0)
			{
				h--;
				e++;
			}
		}
		else if(s[i]=='F')
		{
			if(e>0)
			{
				e--;
				f++;
			}
		}
	}
	cout<<f<<endl;
return 0;
}
