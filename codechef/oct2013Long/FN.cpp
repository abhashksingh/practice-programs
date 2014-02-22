#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
vector <long long> fArr;

void fillArr(long long p);
long long find(long long c);

int main()
{
	int T;
	long long C,P;
	cin>>T;
	while(T--)
	{
		cin>>C>>P;
		fArr.clear();
		fillArr(P);
		cout<<find(C)<<endl;
	}
}

void fillArr(long long p)
{
	fArr.clear();
	long long t1=0,t2=1,t3,i=0,lim;
	if(p%5==1||p%5==4)
	{
		lim=p-1;
	}
	else if(p%5==2||p%5==3)
	{
		lim=2*p+2;
	}
	for(i=0;i<lim;i++)
	{
		if(i==0)
		{
			fArr.push_back(t1%p);
		}
		else if(i==1)
		{
			fArr.push_back(t2%p);
		}
		else
		{
			t3=t1+t2;
			fArr.push_back(t3%p);
			t1=t2;
			t2=t3;
		}
	}
}

long long find(long long c)
{
	long long ret=-1,i=0,siz=fArr.size();
	for(i=0;i<siz;i++)
	{
		//cout<<fArr[i]<<endl;
		if(fArr[i]==c)
		{
			ret=i;
			break;
		}
	}
	return ret;
}
