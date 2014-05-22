#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > possibilities;

void populatePossibilities();

int main()
{
	populatePossibilities();
	long long t,ts;
	while(cin>>t)
	{
		ts = t%30;
		if(binary_search (possibilities.begin(), possibilities.end(), ts))
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
}

void populatePossibilities()
{
	possibilities.push_back(0);
	possibilities.push_back(1);
	possibilities.push_back(3);
	possibilities.push_back(6);
	possibilities.push_back(7);
	possibilities.push_back(9);
	possibilities.push_back(12);
	possibilities.push_back(13);
	possibilities.push_back(15);
	possibilities.push_back(18);
	possibilities.push_back(19);
	possibilities.push_back(21);
	possibilities.push_back(24);
	possibilities.push_back(25);
	possibilities.push_back(27);
	possibilities.push_back(30);
}
