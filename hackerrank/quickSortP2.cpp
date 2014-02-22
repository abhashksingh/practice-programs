#include <vector>
#include <iostream>
#include <algorithm>  

using namespace std;
/* Head ends here */
void printVect(vector<int>ar);
void swap(int &a,int &b);

void quickSort(vector <int>  &ar,int ar_size)
{
	if(ar_size<2) return;
	vector <int> less;
	vector <int> more;
	int p=ar[0];
	for(int i=1;i<ar_size;i++)
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
	quickSort(less,less.size());
	quickSort(more,more.size());
	less.push_back(p);
	merge(less.begin(),less.end(),more.begin(),more.end(),ar.begin());
	printVect(ar);
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
	quickSort(_ar,_ar_size);
return 0;
}

void printVect(vector<int>ar)
{
	for(int i=0;i<ar.size();i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}



