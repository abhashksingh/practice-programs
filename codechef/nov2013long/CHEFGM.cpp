#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const long long V=256;

long long getValue(vector<int> a);

int main()
{
	int t,k,i,temp,ni,j;
	long long trueV,tempV;
	cin>>t;
	cout<<t<<endl;
	while(t--)
	{
		trueV=0;
		for(i=0;i<k;i++)
		{
			vector <int> vec;
			cin>>ni;
			cout<<ni<<endl;
			for(j=0;j<ni;j++)
			{
				cin>>temp;
				vec.push_back(temp);
				cout<<vec[j]<<"  ";
			}
			sort(vec.begin(),vec.end());
			trueV+=getValue(vec);
		}
		
		/*for(i=0;i<k;i++)
		{
			trueV+=getValue(nums[i]);
		}
		cout<<trueV;
		if(trueV > 0)
		{
			cout<<"EVEN"<<endl;
		}
		else if(trueV < 0)
		{
			cout<<"ODD"<<endl;
		}
		else
		{
			cout<<"DON'T PLAY"<<endl;
		}*/
	}
return 0;
}


long long getValue(vector<int> a)
{
	bool flipped=false;
	long long ret=0,tempV=0;
	int siz=a.size(),i,power=1;
	for(i=0;i<siz;i++)
	{
		cout<<a[i]<<"  ";
		if(!flipped)
		{
			if(a[i]%2==0)
			{
				tempV+=V;
			}
			else if(a[i]%2==1)
			{
				tempV-=V;
			}
			if((a[i]%2==0)&&(a[i-1]%2==1))
			{
				flipped=true;
			}
			else if((a[i]%2==1)&&(a[i-1]%2==0))
			{
				flipped=true;
			}
		}
		else if(flipped)
		{
			if(a[i]%2==0)
			{
				tempV+=V/(long long)pow(2,power++);
			}
			else if(a[i]%2==1)
			{
				tempV-=V/(long long)pow(2,power++);
			}
		}
	}
	cout<<endl;
	ret=tempV;
	return ret;
}
