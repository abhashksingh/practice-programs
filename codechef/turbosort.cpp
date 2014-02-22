#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;


bool myfunction (int i,int j)
{
	return (i<j);
}

int main()
{
	vector <int> a;
	int t,i;
	scanf("%d",&t);;
	while(t--)
	{
		scanf("%d",&i);
		a.push_back(i);
	}
	sort(a.begin(), a.end(), myfunction);
	for(int j=0;j<a.size();j++)
		printf("%d\n",a[j]);
}
