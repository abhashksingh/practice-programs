#include <iostream>

using namespace std;
long long square(long long x);
void sort(long long **arr);
int main()
{
	int n,count=0;
	long long x1,y1,x2,y2,x3,y3;
	cin>>n;
	//cout<<n<<endl;
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
		long long* darr = new long long[3];
		darr[0]=square(x2-x1)+square(y2-y1);
		darr[1]=square(x3-x1)+square(y3-y1);
		darr[2]=square(x3-x2)+square(y3-y2);
		//cout<<darr[0]<<"  "<<darr[1]<<"  "<<darr[2]<<endl;
		sort(&darr);
		//cout<<darr[0]<<"  "<<darr[1]<<"  "<<darr[2]<<endl<<endl<<endl;
		if(darr[2]==(darr[0]+darr[1]))
		{
			count++;
		}
	}
	cout<<count<<endl;
}

long long square(long long x)
{
	return x*x;
}

void sort(long long **arr)//for sorting array of 3 numbers
{
	long long *a =new long long[3];
	a=*arr;
	long long temp;
	if(a[0]>a[1] && a[0]>a[2])
	{
		temp=a[0];
		a[0]=a[2];
		a[2]=temp;
	}
	else if(a[1]>a[0] && a[1]>a[2])
	{
		temp=a[1];
		a[1]=a[2];
		a[2]=temp;
	}
}
