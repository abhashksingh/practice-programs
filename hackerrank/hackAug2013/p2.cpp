#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b);
void secondMax(int arr[],int size,int &max,int &secondMax);
char correspondingChar(int i);

int main()
{
	string inp;
	getline(cin,inp);
	//cout<<inp<<endl;
	int *chrs=new int[26];
	int i=0;
	for(i=0;i<inp.size();i++)
	{
		chrs[inp[i]-97]++;
	}
	for(i=0;i<26;i++)
	{
		//chrs[i]=chrs[i]/norm;
		//cout<<correspondingChar(i)<<": "<<chrs[i]<<"\t";
	}
	int max=0,smax=0;
	secondMax(chrs,26,max,smax);
	cout<<max<<" "<<smax<<endl;
	int norm=gcd(max,smax);
	for(i=0;i<26;i++)
	{
		chrs[i]=chrs[i]/norm;
		//cout<<correspondingChar(i)<<": "<<chrs[i]<<"\t";
	}
	//cout<<endl;
	string out="";
	int j=0;
	for(i=0;i<26;i++)
	{
		for(j=0;j<chrs[i];j++)
		{
			out = out+correspondingChar(i);
		}
	}
	cout<<out<<endl;
}

int gcd(int a,int b)
{
	int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void secondMax(int arr[],int size,int &max,int &secondMax)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]>max)
		{
			secondMax=max;
			max=arr[i];
		}
		else if(arr[i]>secondMax)
		{
			secondMax=arr[i];
		}
	}
}

char correspondingChar(int i)
{
	char ch;
	switch (i)
	{
		case 0:
			ch='a';
			break;
		case 1:
			ch='b';
			break;
		case 2:
			ch='c';
			break;
		case 3:
			ch='d';
			break;
		case 4:
			ch='e';
			break;
		case 5:
			ch='f';
			break;
		case 6:
			ch='g';
			break;
		case 7:
			ch='h';
			break;
		case 8:
			ch='i';
			break;
		case 9:
			ch='j';
			break;
		case 10:
			ch='k';
			break;
		case 11:
			ch='l';
			break;
		case 12:
			ch='m';
			break;
		case 13:
			ch='n';
			break;
		case 14:
			ch='o';
			break;
		case 15:
			ch='p';
			break;
		case 16:
			ch='q';
			break;
		case 17:
			ch='r';
			break;
		case 18:
			ch='s';
			break;
		case 19:
			ch='t';
			break;
		case 20:
			ch='u';
			break;
		case 21:
			ch='v';
			break;
		case 22:
			ch='w';
			break;
		case 23:
			ch='x';
			break;
		case 24:
			ch='y';
			break;
		case 25:
			ch='z';
			break;
	}
return ch;
}
