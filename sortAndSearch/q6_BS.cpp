#include <iostream>

using namespace std;

class Coordinate
{
	public:
	int row;
	int column;
	Coordinate()
	{
		row=-1;
		column=-1;
	}
	Coordinate(int r,int c)
	{
		row=r;
		column=c;
	}
	
	bool inbounds(int** matrix)
	{
		int c=sizeof(matrix[0])/sizeof(int);
		int r=sizeof(matrix)/sizeof(matrix[0]);
		return (row>=0 && column>=0 && row<r && column<c);
	}
	
	bool isBefore(Coordinate p)
	{
		return ((row<=p.row)&&(column<=p.column));
	}
	void setToAverage(Coordinate min,Coordinate max)
	{
		row=(min.row+max.row)/2;
		column=(min.column+max.column)/2;
	}
};

int min(int a,int b);
Coordinate parttitionAndSearch(int** matrix,Coordinate origin,Coordinate dest,Coordinate pivot,int elem);
Coordinate findElement(int** matrix,Coordinate origin,Coordinate dest,int x);

static Coordinate findElement(int** matrix,int x)
{
	Coordinate origin(0,0);
	int c=sizeof(matrix[0])/sizeof(int);
	int r=sizeof(matrix)/sizeof(matrix[0]);
	Coordinate destination(c-1,r-1);
	return findElement(matrix,origin,destination,x);
}

int main()
{
	int** matrix=new int*[4];
	for(int i=0;i<4;i++)
	{
		matrix[i]=new int[4];
	}
	matrix[0][0]=15;
	matrix[0][1]=20;
	matrix[0][2]=40;
	matrix[0][3]=85;
	matrix[1][0]=20;
	matrix[1][1]=35;
	matrix[1][2]=80;
	matrix[1][3]=95;
	matrix[2][0]=30;
	matrix[2][1]=55;
	matrix[2][2]=95;
	matrix[2][3]=105;
	matrix[3][0]=40;
	matrix[3][1]=80;
	matrix[3][2]=100;
	matrix[3][3]=120;
	findElement(matrix,80);
return 0;
}

Coordinate findElement(int** matrix,Coordinate origin,Coordinate dest,int x)
{
	if(!origin.inbounds(matrix)||!dest.inbounds(matrix))
	{
		Coordinate invalid;
		return invalid;
	}
	if(matrix[origin.row][origin.column]==x)
	{
		return origin;
	}
	else if(!origin.isBefore(dest))
	{
		Coordinate invalid;
		return invalid;
	}
	/*Set the Start of diagonal and end to the end of diagonal
	 * Since the grid may not be square,
	 * the end of diagonal may not equal dest*/
	Coordinate start=origin;
	int diagDist=min(dest.row-origin.row,dest.column-origin.column);
	Coordinate end(start.row+diagDist,start.column+diagDist);
	Coordinate p(0,0);
	while(start.isBefore(end))
	{
		p.setToAverage(start,end);
		if(x>matrix[p.row][p.column])
		{
			start.row=p.row+1;
			start.column=p.column+1;
		}
		else
		{
			end.row=p.row-1;
			end.column=p.column-1;
		}
	}
	/*Split the grid into quadrants.Search the bottom left and top right.*/
	return parttitionAndSearch(matrix,origin,dest,start,x);
}

Coordinate parttitionAndSearch(int** matrix,Coordinate origin,Coordinate dest,Coordinate pivot,int elem)
{
	Coordinate invalid;
	Coordinate lowerLeftOrigin(pivot.row,origin.column);
	Coordinate lowerLeftDest(dest.row,pivot.column-1);
	Coordinate upperRightOrigin(origin.row,pivot.column);
	Coordinate upperRightDest(origin.row-1, dest.column);
	Coordinate lowerLeft=findElement(matrix,lowerLeftOrigin,lowerLeftDest,elem);
	if((lowerLeft.row==invalid.row)&&(lowerLeft.column==invalid.column))
	{
		return findElement(matrix,upperRightOrigin,upperRightDest,elem);
	}
return lowerLeft;
}

int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
