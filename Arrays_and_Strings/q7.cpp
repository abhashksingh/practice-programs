/*Write an algorithm such that if an element in an M*N matrix is 0,its entire row and column are 0
 * here M and N are not zeroes and not equal to 1*/
/*Find out about 2d arrays being passed */
#include <iostream>
using namespace std;
int** turntozero(int **a,int row,int col);
int main()
{
	int rows,columns;
	cout<<"Enter the number of rows: ";
	cin>>rows;
	cout<<"Enter the number of columns: ";
	cin>>columns;
	int **matrix;
	matrix = new int*[rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]= new int[columns];
	}
	cout<<"Keep entering "<<rows*columns<<" elements"<<endl;
	//initialising the array
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cin>>matrix[i][j];
		}
	}
	turntozero(matrix,rows,columns);
}

int** turntozero(int **a,int rows,int cols)
{
	int i=0,j=0;
	bool row[rows],column[cols];
	for(i=0;i<rows;i++)
		row[i]=false;
	for(j=0;j<cols;j++)
		column[j]=false;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			if(a[i][j]==0)
			{
				row[i]=true;
				column[j]=true;
			}
		}
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			if(row[i]||column[j])
			{
				a[i][j]=0;
			}
		}
	}
return a;
}
