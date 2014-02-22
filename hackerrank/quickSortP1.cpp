#include <vector>
#include <iostream>

using namespace std;
/* Head ends here */
void shift(vector <int> &ar ,int pos,int i);
void printVect(vector<int>ar);
void swap(int &a,int &b);

void partition(vector <int>  ar)
{
	vector <int> less;
	vector <int> more;
	int p=ar[0],size=ar.size();
	for(int i=0;i<size;i++)
	{
		if(ar[i]>p)
		{
			more.push_back(ar[i]);
		}
		else if(ar[i]<p)
		{
			less.push_back(ar[i]);
		}
	}
	printVect(less);
	cout<<p<<" ";
	printVect(more);
	cout<<endl;
}
/* Tail starts here */
int main()
{
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for(int _ar_i=0; _ar_i<_ar_size; _ar_i++)
	{
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp);
	}
	partition(_ar);
return 0;
}

void printVect(vector<int>ar)
{
	for(int i=0;i<ar.size();i++)
	{
		cout<<ar[i]<<" ";
	}
	//cout<<endl;
}

void shift(vector <int> &a,int pos,int i)
{
	int t=a[pos];
	a[pos]=a[i];
	for(int j=pos+1;j<a.size();j++)
	{
		swap(t,a[j]);
	}
}

void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}



