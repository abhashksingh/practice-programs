#include <iostream>

using namespace std;

int numberOfChocolates(int N, int C)
{
	return N / C;
}

//calculate how much chocolate we can buy with the wrappers
int numberOfChocolatesForWrappers(int chocolates, int M)
{
	int result = 0;
	while (chocolates / M > 0)
	{
		result += chocolates / M; //chocolate we can get
		//chocolates we can get + chocolate/ wrappers unused
		chocolates = (chocolates / M) + (chocolates % M);
	}
return result;
}

int main()
{
	int T,N,C,M,i;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>N>>C>>M;
		int totChocolates = 0;
		totChocolates = numberOfChocolates(N, C) + numberOfChocolatesForWrappers(numberOfChocolates(N, C), M);
		cout<<totChocolates<<endl;
	}
}
