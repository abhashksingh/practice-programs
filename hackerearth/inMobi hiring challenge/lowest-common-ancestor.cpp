#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lca(int *pArr,int N,int* uArr,int M);
bool arrEqual(int* a,int N);

int main()
{
	int N,i=0,M;
	cin>>N;
	//cout<<N<<endl;
	int *parentArr=new int[N];
	parentArr[0]=0;
	for(i=1;i<N;i++)
	{
		cin>>parentArr[i];
	}
	/*for(i=1;i<N;i++)
	{
		cout<<parentArr[i];
	}
	cout<<endl;*/
	cin>>M;
	//cout<<M<<endl;
	int *uArr=new int[M];
	for(i=0;i<M;i++)
	{
		cin>>uArr[i];
	}
	/*for(i=0;i<M;i++)
	{
		cout<<uArr[i];
	}
	cout<<endl;*/
	//lca(parentArr,N,uArr,M);
	cout<<lca(parentArr,N,uArr,M)<<endl;
return 0;
}

int lca(int *pArray,int M,int* uArray,int N)
{
	//cout<<M<<"   "<<N<<endl;
	/*for(int i=0;i<N;i++)
	{
		cout<<uArray[i]<<"  ";
	}*/
	while(!arrEqual(uArray,N))
	{
		for(int i=N-1;i>=0;i--)
		{
			uArray[i]=pArray[(uArray[i])];
			if(arrEqual(uArray,N)){break;}
		}
	}
	return uArray[0];
}

bool arrEqual(int* a,int N)
{
	bool ret=true;
	int b=a[0];
	for(int i=0;i<N;i++)
	{
		if(b!=a[i])
		{
			ret=false;
			break;
		}
	}
return ret;
}
