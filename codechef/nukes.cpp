#include <iostream>

using namespace std;

int a,n,k;

int main(void)
{
	cin>>a>>n>>k;
	n++ ;
	while (k--)
	{
		cout<<a%n<<" ";
		a=a/n ;
	}
return 0 ;
}
