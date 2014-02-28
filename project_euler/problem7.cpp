#include <iostream>
#include <math.h>  

using namespace std;  


bool isPrime(int p)
{
	bool result = true;
	int lim = (int)(ceil(sqrt(p)));
	for(int i=2; i<=lim; i++)
	{
		if(p % i == 0)
		{
			result = false;  
			break;  
		}  
	}
return result;  
}

int main()  
{
	int n = 2;
	int ends = 10001;
	for(int i=1; i != ends; n++)
	{
		if(isPrime(n) == true)
		{
			i += 1;
		}
		/*if(n==104743)*/if(i == ends)
		{
			cout<<i<<endl;
			break;}
	}
	cout << n;
return 0;  
}  
