#include <iostream>

using namespace std;

long long ret;

void modify(long long a);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ret=0;
		long long a;
		cin>>a;
		modify(a);
		cout<<ret<<endl;
	}
}

void modify(long long a)
{
	if(a==0)
	{return;}
	else if(a==1)
	{
		ret+=1;
		modify(a-1);
	}
	else if(a>=2 && a<4)
	{
		ret++;
		modify(a-2);
	}
	else if(a>=4 && a<8)
	{
		ret++;
		modify(a-4);
	}
	else if(a>=8 && a<16)
	{
		ret++;
		modify(a-8);
	}
	else if(a>=16 && a<32)
	{
		ret++;
		modify(a-16);
	}
	else if(a>=32 && a<64)
	{
		ret++;
		modify(a-32);
	}
	else if(a>=64 && a<128)
	{
		ret++;
		modify(a-64);
	}
	else if(a>=128 && a<256)
	{
		ret++;
		modify(a-128);
	}
	else if(a>=256 && a<512)
	{
		ret++;
		modify(a-256);
	}
	else if(a>=512 && a<1024)
	{
		ret++;
		modify(a-512);
	}
	else if(a>=1024 && a<2048)
	{
		ret++;
		modify(a-1024);
	}
	else if(a>=2048)
	{
		ret++;
		modify(a-2048);
	}
}
