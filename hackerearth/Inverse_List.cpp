#include <iostream>
using namespace std;
bool compareArrays(int **a,int **b,int size);

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		bool inv;
		int size;
		int* arr,*barr;
		cin>>size;
		arr=new int[size];
		barr=new int[size];
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<size;i++)
		{
			barr[arr[i]-1]=i+1;
		}
		inv = compareArrays(&arr,&barr,size);
		if(inv)
		{
			cout<<"inverse"<<endl;
		}
		else
		{
			cout<<"not inverse"<<endl;
		}
	}
    
    return 0;
}

bool compareArrays(int **ar,int **br,int size)
{
	bool ret=true;
	int *a=new int[size];
	a=*ar;
	int *b=new int[size];
	b=*br;
	for(int i=0;i<size;i++)
	{
		if(a[i]!=b[i])
		{
			ret=false;
			break;
		}
	}
return ret;
}
