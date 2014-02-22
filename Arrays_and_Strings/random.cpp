#include<iostream>
using namespace std;
int main()
{
	float i=234.0;
	char a=*(char*)&i;
	cout<<a;
	
}
