#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

bool allNines(int*a,int digit);
long long roundUp(long long num,int dig);
long long arrayToNum(int* a,int digits);
long long fairAndSquare(long long r1,long long r2);
bool isPalindrome(long long num);
long long getNextPalindrome(long long num);
int numDigits(long long num);

int main()
{
	long long T,i=0,index=0;
	cin>>T;
	for(i=0;i<T;i++)
	{
		long long r1,r2;
		cin>>r1>>r2;
		cout<<"Case #"<<i+1<<": "<<fairAndSquare(r1,r2)<<endl;
		//fairAndSquare(r1,r2);
		//cout<<r1<<"  "<<r2<<endl;;
	}
return 0;
}

long long fairAndSquare(long long r1,long long r2)
{
	long long count=0,i=r1;
	//cout<<i<<"  "<<r2<<endl;
	while(i<=r2)
	{
		long long root=sqrt(i);
		//cout<<root<<endl;
		bool pal=isPalindrome(i);
		bool rpal=isPalindrome(root);
		long long sqr=root*root;
		bool perfect=(sqr==i);
		//cout<<root<<"  "<<pal<<"  "<<rpal<<"  "<<perfect<<endl;
		if(pal&&rpal&&perfect)
		{
			count++;
		}
		long long next=getNextPalindrome(root);
		i=(next)*(next)-1;
		i++;
	}
return count;
}

bool isPalindrome(long long num)
{
	long long rev=0,temp=num;
	while(temp!=0)
	{
		rev = (rev*10)+(temp%10);
		temp = temp/10;
	}
	//cout<<num<<endl;
	if(rev==num) return true;
	else return false;
}

int numDigits(long long num)
{
	int count=0;
	while(num!=0)
	{
		num=num/10;
		count++;
	}
	return count;
}

long long getNextPalindrome(long long num)
{
	if(num>0 && num<9)
	{
		return (num+1);
	}
	else if(num>=9 && num< 100)
	{
		return (num+(11-(num%11)));
	}
	else
	{
		long long t = num;
		int digit=numDigits(num);
		int* numArray = new int[digit];
		for(int i=0;i<digit;i++)
		{
			numArray[i]=(t%10);
			t=t/10;
		}
		if(allNines(numArray,digit))
		{
			return num+2;
		}
		else
		{
			int mid=numArray[(digit/2)];
			if(mid!=9)
			{
				for(int i=(digit/2);i<digit;i++)
				{
					numArray[i]=numArray[digit-i-1];
				}
				long long tmp=arrayToNum(numArray,digit);
				if(tmp>num)
				{
					return tmp;
				}
				else
				{
					numArray[(digit/2)]++;
					return arrayToNum(numArray,digit);
				}
			}
			else
			{
				return getNextPalindrome(roundUp(num,digit));
			}
		}
	delete numArray;
	}
}

long long arrayToNum(int* a,int digits)
{
	long long num=0;
	for(int i=0;i<digits;i++)
	{
		num=(num*10)+a[i];
	}
return num;
}

long long roundUp(long long num,int dig)
{
	long long increment=pow(10,((dig/2)+1));
	return (num+increment);
}

bool allNines(int*a,int digit)
{
	for(int i=0;i<digit;i++)
	{
		if(a[i]!=9) return false;
	}
return true;
}
