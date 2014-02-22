#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

void print(int i);

int main()
{
	int M,K;
	cin>>M>>K;
	int busy[1440];
	int a1,a2,b1,b2;
	int i;
	for(i=0;i<1440;i++)
	{
		busy[i]=0;
	}
	while(M--)
	{
		cin>>a1>>a2>>b1>>b2;
		int start = a1*60+a2;
		int end = b1*60+b2;
		for(i=start;i<end;i++)
		{
			busy[i]=1;
		}
	}
	int j;
	i=0;
	while(i<1440)
	{
		j=i;
		if(busy[j] == 1)
		{
			i++;
			continue;
		}
		while(j < 1440 && busy[++j]==0);
		
		if((j-i)>=K)
		{
			print(i);
			cout << " ";
			print(j); 
			cout << endl;
		}
		i=j;
	}
}


void print(int i)
{
	if(i==0 || i==1440) cout << "00 00";
	else
	{
		int j = i/60;
		int k = i%60; 
		if(j<10) cout << "0" << j << " ";
		else cout << j << " ";
		if(k<10) cout << "0" << k ;
		else cout << k ;
	}
}
