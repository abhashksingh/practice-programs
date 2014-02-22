#include <iostream>
using namespace std;
void possible_replacements(int s,int *rep1,int *rep2,int *rep3,int *rep4,int *rep5,int* rep6,int* rep7);
int digits(int num);
int reverse(int num);
int select_suitable(int arr[6],int max);

int main()
{
	bool conversion_matrix[10][10]={
									{true,false,false,false,false,false,false,false,true,false},//0
									{true,true,false,true,true,false,false,true,true,true},//1
									{false,false,true,false,false,false,false,false,true,false},//2
									{false,false,false,true,false,false,false,true,true,},//3
									{false,false,false,false,true,false,false,false,true,true},//4
									{false,false,false,false,false,true,true,false,true,true},//5
									{false,false,false,false,false,false,true,false,true,false},//6
									{true,false,false,true,false,false,false,true,true,true},//7
									{false,false,false,false,false,false,false,false,true,false},//8
									{false,false,false,false,false,false,false,false,true,true}//9
								};
	int t,s,m,temps,tempm,digits_of_s[8],digits_of_m[8],i=0,rep[7];
	cin>>t;
	for(i=0;i<8;i++)
	{
		digits_of_s[i]=0;
		digits_of_m[i]=0;
	}
	while(t!=0)
	{
		cin>>s;
		cin>>m;
		temps=s;
		tempm=m;
		//cout<<s<<" "<<m<<endl;
		if((m==s)||(s==0))
		{
			cout<<m<<endl;
		}
		else if(m>s)
		{
			int digm = digits(m);
			int digs = digits(s);
			for(i=0;i<digs;i++)
			{
				digits_of_s[i]=temps%10;
				temps=temps/10;
			}
			for(i=0;i<digm;i++)
			{
				digits_of_m[i]=tempm%10;
				tempm=tempm/10;
			}
			if(digs==digm)
			{
				for(i=0;i<digs-1;i++)
				{
					if(conversion_matrix[digits_of_s[i]][digits_of_m[i]])
					{
						digits_of_s[i]=digits_of_m[i];
					}
					else
					{
						possible_replacements(digits_of_s[i],&rep[0],&rep[1],&rep[2],&rep[3],&rep[4],&rep[5],&rep[6]);
						digits_of_s[i]=rep[6];
					}
				}
				possible_replacements(digits_of_s[digs-1],&rep[0],&rep[1],&rep[2],&rep[3],&rep[4],&rep[5],&rep[6]);
				digits_of_s[digs-1]=select_suitable(rep,digits_of_m[digs-1]);
				temps=0;
				for(i=digs;i>=0;i--)
				{
					temps=(temps*10)+digits_of_s[i];
					
				}
				//temps=reverse(temps);
				cout<<temps<<endl;
			}
			else if(digm>digs)
			{
				if(digits_of_m[digs-1]==digits_of_s[digs-1])
				{
					possible_replacements(digits_of_s[digs-2],&rep[0],&rep[1],&rep[2],&rep[3],&rep[4],&rep[5],&rep[6]);
					digits_of_m[digs-2]=select_suitable(rep,digits_of_m[digs-2]);
					for(i=digs-3;i>=0;i--)
					{
						possible_replacements(digits_of_s[i],&rep[0],&rep[1],&rep[2],&rep[3],&rep[4],&rep[5],&rep[6]);
						digits_of_m[i]=rep[6];
					}
				}
				else
				{
					for(i=0;i<digs;i++)
					{
						if(!conversion_matrix[digits_of_s[i]][digits_of_m[i]])
						{
							possible_replacements(digits_of_s[i],&rep[0],&rep[1],&rep[2],&rep[3],&rep[4],&rep[5],&rep[6]);
							digits_of_m[i]=rep[6];
						}
					}
				}
				temps=0;
				for(i=digm-1;i>=0;i--)
				{
					temps=(temps*10)+digits_of_m[i];
				}
				if(temps>m)
				{
					tempm=1;
					for(i=0;i<digs;i++)
					{
						tempm*=10;
					}
					temps=temps-(tempm);
				}
				cout<<temps<<endl;
			}
		}
		t--;
	}
}

int select_suitable(int arr[7],int max)
{
	int r=0;
	for(int i=0;i<7;i++)
	{
		if((r<arr[i])&&(arr[i]<=max))
		{
			r=arr[i];
		}
	}
	return r;
}

int digits(int num)
{
	int i=0;
	while(num>0)
	{
		i++;
		num=num/10;
	}
	return i;
}

void possible_replacements(int s,int *rep1,int *rep2,int *rep3,int *rep4,int *rep5,int* rep6,int* rep7)
{
	switch(s)
	{
		case 0 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=0;
			*rep7=8;
			break;
		case 1 :
			*rep1=0;
			*rep2=1;
			*rep3=3;
			*rep4=4;
			*rep5=7;
			*rep6=8;
			*rep7=9;
			break;
		case 2 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=2;
			*rep7=8;
			break;
		case 3 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=3;
			*rep6=8;
			*rep7=9;
			break;
		case 4 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=4;
			*rep6=8;
			*rep7=9;
			break;
		case 5 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=5;
			*rep5=6;
			*rep6=8;
			*rep7=9;
			break;
		case 6 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=6;
			*rep7=8;
			break;
		case 7 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=3;
			*rep5=7;
			*rep6=8;
			*rep7=9;
			break;
		case 8 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=0;
			*rep7=8;
			break;
		case 9 :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=8;
			*rep7=9;
			break;
		default :
			*rep1=0;
			*rep2=0;
			*rep3=0;
			*rep4=0;
			*rep5=0;
			*rep6=0;
			*rep7=0;
	}
}

int reverse(int num)
{
	int rev=0;
	int i;
	while(num>0)
	{
		i=(num%10);
		rev=(rev*10)+i;
		num=num/10;
	}
	return rev;
}
