#include <iostream>

using namespace std;

int find_complement(int* arr,int val,int startl,int size);

int main()
{
	int N,i,index=0,C,I,pos1,pos2;
	cin>>N;
	for(index=0;index<N;index++)
	{
		cin>>C;
		cin>>I;
		int arr[I];
		for(i=0;i<I;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<I;i++)
		{
			if(arr[i]>C)
			{
				continue;
			}
			else if(arr[i]<C)
			{
				int res=find_complement(arr,C-arr[i],i+1,I);
				if(res>0)
				{
					if(res>i)
					{
						pos1=i+1;
						pos2=res+1;
					}
					else if(i>res)
					{
						pos1=res+1;
						pos2=i+1;
					}
					break;
				}
			}
		}
		cout<<"Case #"<<index+1<<":"<<pos1<<" "<<pos2<<endl;
	}
}

int find_complement(int* arr,int val,int startl,int size)
{
	int res=-1;
	for(int i=startl;i<size;i++)
	{
		if(val==arr[i])
		{
			res=i;
			break;
		}
	}
return res;
}
