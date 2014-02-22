#include <iostream>

using namespace std;

bool findElement(int matrix[4][4],int elem);

int main()
{
	int a[4][4]={{15,20,40,85},{20,35,80,95},{30,55,95,105},{40,80,100,120}};
	cout<<findElement(a,80)<<endl;
return 0;
}

bool findElement(int matrix[4][4],int elem)
{
	int row=0;
	int len=sizeof(matrix[0])/sizeof(int);
	int col=len-1;
	while(row<len && col>=0)
	{
		if(matrix[row][col]==elem)
		{
			cout<<"Row is : "<<row<<endl;
			cout<<"Column is : "<<col<<endl;
			return true;
		}
		else if(matrix[row][col]>elem)
		{
			col--;
		}
		else
		{
			row++;
		}
	}
return false;
}
