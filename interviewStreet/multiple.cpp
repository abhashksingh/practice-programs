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


int getXNumber(int n) {
	vector <long long> list;
	long long i=0;
	//accumulating all factors <10
	for(i=2;i<10;i++)
	{
		if(n%i == 0)
		{
			//cout<<i<<endl;
			list.push_back(i);
		}
	}
	if(list.empty()){return -1;}
	//sort(list.begin(), list.end());
	long long x=0;
	vector <long long> powerList;
	for(i=0;i<list.size();i++)
	{
		long long cnt=0,b=list[i];
		while(n%b==0)
		{
			cnt++;
			b=b*list[i];
		}
		cout<<list[i]<<"  "<<cnt<<endl;
		powerList.push_back(cnt);
	}
	long long t=1;
	for(i=list.size()-1;i>=0;i--)
	{
		bool l=false;
		while(powerList[i]>0)
		{
			x=(x*10)+list[i];
			powerList[i]--;
			t=t*list[i];
			if(t==n)
			{
				l=true;
				break;
			}
		}
		if(l){break;}
	}
	//reversing the number now
	long long temp =0;
	if(t!=n){return -1;}
	while(x>0)
	{
		temp = (temp*10)+(x%10);
		x=x/10;
	}
	return temp;
}



int main()
{
	/*cout<<*/
	cout<<getXNumber(26);
}
