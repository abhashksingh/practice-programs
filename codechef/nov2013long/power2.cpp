#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long c=10000007;

long long multiply2(long long i)
{
	return i*2;
}

int main()
{
	long long count=0,init=1;
	while(init<=c)
	{
		init=multiply2(init);
		cout<<init<<","<<endl;
		count++;
	}
	cout<<"\n\nCount is :"<<count<<endl;
	cout<<16777216%c<<endl;
return 0;
}
