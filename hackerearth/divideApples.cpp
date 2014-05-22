#include <stdio.h>
#include <iostream>

using namespace std;

int *array;
int i,j,count,num,avg,sum,flag=1;

int check();

int main()

{
	int ans;
	scanf("%d",&num);
	array = new int[num];
	i=0;
	while(i<num)
	{
		scanf("%d",&array[i]);
		sum+=array[i];
		i++;
	}
	avg = sum/num;
	while((ans=check())==1)
	{
		if(array[i]>avg && array[0]<avg)
		{
			array[i]-=1;
			array[0]+=1;
			count++;
		}
		if(array[i]<avg && array[0]>avg)
		{
			array[i]+=1;
			array[0]-=1;
			count++;
		}
		i=0;
		while(j<i)
		{
			if(array[i+j-1]>avg && array[i+j-2]<avg)
			{
				array[i+j-1]-=1;
				array[i+j-2]+=1;
				count++;
			}
			if(array[i+j-1]<avg && array[i+j-2]>avg)
			{
				array[i+j-1]+=1;
				array[i+j-2]-=1;
				count++;
			}
			j++;
		}
		printf("%d",count);
		return 0;
	}
}

int check()
{
	while(i<num)
	{
		if(array[i]!=avg)
		{
			flag=0;
			continue;
			i++;
		}
	}
	if(flag=0)
		return 0;
	return 1;
}
