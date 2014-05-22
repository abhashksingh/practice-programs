#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

bool checkRow(int** darr,int n,int m,int row);
bool checkColumn(int** darr,int n,int m,int col);
bool checkRowWise(int** darr,int n,int m);
bool checkColumnWise(int** darr,int n,int m);

int main()
{
	int T,i=0,j=0,k=0,index=0,m,n;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>n>>m;//n row m column
		if(n==1)
		{
			if(m>3)
			{
				bool val=true;
				int* darr = new int[m];
				for(index=2;index<m-1;index++)
				{
					if(darr[index]==darr[index-1])
					{
						val=(val&&true);
					}
					else
					{
						val=(val&&false);
						break;
					}
				}
				if(val){cout<<"Case #"<<i+1<<" "<<"YES"<<endl;}
				else{cout<<"Case #"<<i+1<<" "<<"NO"<<endl;}
			}
			else
			{
				cout<<"Case #"<<i+1<<" "<<"YES"<<endl;
			}
		}
		else if(m==1)//temporarily m row and n column
		{
			if(n>3)
			{
				bool val=true;
				int* darr = new int[n];
				for(index=2;index<n-1;index++)
				{
					if(darr[index]==darr[index-1])
					{
						val=(val&&true);
					}
					else
					{
						val=(val&&false);
						break;
					}
				}
				if(val){cout<<"Case #"<<i+1<<" "<<"YES"<<endl;}
				else{cout<<"Case #"<<i+1<<" "<<"NO"<<endl;}
				delete(darr);
			}
			else
			{
				cout<<"Case #"<<i+1<<" "<<"YES"<<endl;
			}
		}

		else
		{
			int** darr= new int*[n];
			for(j=0;j<n;j++)
			{
				darr[j]= new int[m];
			}
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++)
				{
					cin>>darr[j][k];
				}
			}
			bool val1=checkRowWise(darr,n,m);
			bool val2=checkColumnWise(darr,m,n);
			if(val1||val2) cout<<"Case #"<<i+1<<" "<<"YES"<<endl;
			else cout<<"Case #"<<i+1<<" "<<"NO"<<endl;
			for(j=0;j<n;j++)
			{
				delete(darr[j]);
			}
			delete(darr);
		}
	}
	
return 0;
}
//n=row & m=column
bool checkRowWise(int** darr,int n,int m)
{
	int t;
	//checking start and end rows
	//checking the inner rectangle/square
	for(int i=1;i<n-1;i++)
	{
		t=darr[i][1];
		for(int j=0;i<m-1;i++)
		{
			if(darr[i][j]!=t)
			{
				if(t<darr[i][j]) return false;
				else if((t>=darr[i][j])&& !checkColumn(darr,n,m,i)) return false;
			}
			
		}
	}
return true;
}

//n=row & m=column
bool checkColumnWise(int** darr,int n,int m)
{
	int start,end,t;
	//checking start and end columns
	//checking the inner rectangle/square
	for(int i=1;i<m-1;i++)
	{
		t=darr[i][1];
		for(int j=0;i<n-1;i++)
		{
			if(darr[i][j]!=t)
			{
				if(t<darr[i][j]) return false;
				else if((t>=darr[i][j])&& !checkRow(darr,n,m,i)) return false;
			}
			
		}
	}
return true;
}

//n=row & m=column
bool checkRow(int** darr,int n,int m,int row)
{
	int t=darr[row][0];
	for(int i=0;i<m;i++)
	{
		if(t!=darr[row][i]) return false;
	}
	return true;
}
bool checkColumn(int** darr,int n,int m,int column)
{
	int t=darr[0][column];
	for(int i=0;i<m;i++)
	{
		if(t!=darr[i][column]) return false;
	}
	return true;
}
