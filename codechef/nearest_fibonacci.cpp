/*Round a number to the closest whole integer in the Fibonacci sequence. If two elements in the sequence are equally far away,
 * round up. The sequence should start from 0. (eg 0, 1, 1, 2, 3, 5, 8, 13.....). */
#include <iostream>
#include <vector>

using namespace std;

long long difference(long long a,long long b);
long long find_nearest_fib(long long inp);
void generate_fib_upto(long long inp);

vector <long long> fib;

int main()
{
	long long inp;
	cin>>inp;
	cout<<find_nearest_fib(inp)<<endl;
}

long long find_nearest_fib(long long inp)
{
	generate_fib_upto(inp);
	if(inp==fib[fib.size()-1])
	{
		return inp;
	}
	else if(difference(inp,fib[fib.size()-1])<=difference(inp,fib[fib.size()-2]))
	{
		return fib[fib.size()-1];
	}
	else
	{
		return fib[fib.size()-2];
	}
}
void generate_fib_upto(long long inp)
{
	fib.clear();
	fib.push_back(0);
	fib.push_back(1);
	long long temp1=fib[fib.size()-1];
	long long temp2=fib[fib.size()-2];
	while(temp1<inp)
	{
		fib.push_back(temp1+temp2);
		temp1=fib[fib.size()-1];
		temp2=fib[fib.size()-2];
	}
	
}

long long difference(long long a,long long b)
{
	if((a-b)>0)
	{
		return (a-b);
	}
	else
	{
		return (b-a);
	}
}
