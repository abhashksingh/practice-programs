//permut2
#include <iostream>

using namespace std;

int main()
{
	int a=1, i, arr[100005], arrInv[100005], not_amb;
	while(a!=0)
	{
		cin>>a;
		not_amb=0; 
		for(i=1; i<=a; i++)
		{
			cin>>arr[i];
		}
		for(i=1; i<=a; i++)
		{
			arrInv[arr[i]]=i;
		}
		for(i=1; i<=a; i++)
		{
			if(arr[i]!=arrInv[i]) not_amb=1;
		}
		if(a!=0)
		{
			if(not_amb) cout<<"not ambiguous"<<endl;
			else cout<<"ambiguous"<<endl;
		}
	}
return 0;
}
