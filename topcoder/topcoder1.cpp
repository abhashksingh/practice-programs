#include <iostream>
#include <vector>

using namespace std;

int ran[46]={0};
int find_distinct(vector <int> inp)
{
	vector<int>::iterator it;
	for(it=inp.begin(); it != inp.end() ; it++)
	{
		ran[(*it)-2]++;
	}
	int ret=0;
	for(int i=0;i<46;i++)
	{
		ret+=ran[i];
	}
return ret;
}
int factorial(int a)
{
	int ret=1;
	while(a>0)
	{
		ret*=a;
		a--;
	}
return ret;
}
class TheSwapsDivTwo
{
	public:
	vector<int> a;
	int find(vector <int> sequence)
	{
		int distinct=find_distinct(sequence);
		int ret =(factorial(sequence.size())/(factorial(2)*factorial(distinct)));
	}
};

int main()
{
	TheSwapsDivTwo obj;
	int a;
	while(cin>>a)
	{
		obj.a.push_back(a);
	}
	cout<<obj.find(obj.a)<<endl;

return 0;
}
