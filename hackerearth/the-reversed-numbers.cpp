#include <iostream>
#include <map>

using namespace std;

int reverse(int n1);

int main()
{
	int t;
	int n1,n2;
	cin>>t;
	while(t--)
	{
		cin>>n1>>n2;
		cout<<reverse(reverse(n1)+reverse(n2))<<endl;
	}
}

int reverse(int n1)
{
	int rev=0;
	while(n1>0)
	{
		rev=(rev*10)+(n1%10);
		n1=n1/10;
	}
	return rev;
}
