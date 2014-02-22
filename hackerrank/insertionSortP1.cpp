#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void printVect(vector<int>ar);
void insertionSort(vector <int>  arr)
{
	int i, j, tmp;
	int length=arr.size();
	for(i=length-1;i<length;i++)
	{
		j = i;
		while(j>0 && arr[j-1]>arr[j])
		{
			tmp = arr[j];
			arr[j]=arr[j-1];
			printVect(arr);
			arr[j-1]=tmp;
			j--;
		}
		printVect(arr);
	}
}
/* Tail starts here */
int main(void)
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
	insertionSort(_ar);
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
