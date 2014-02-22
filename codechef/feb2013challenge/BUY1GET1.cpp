#include<stdio.h>
#include<string.h>

int main()
{
	int T;
	int i,j;
	char c[201];
	int arr[52];
	int sum=0;
	scanf("%d",&T);
	while(T>0)
	{
		for(i=0;i<52;i++)
		{
			arr[i]=0;
		}
		scanf("%s",c);
		for(i=0;i<strlen(c);i++)
		{
			if(c[i]>=65 && c[i]<=90)
			{
				arr[(int)c[i]-65]++;
			}
			else if(c[i]>=97 && c[i]<=122)
			{
				arr[(int)c[i]-71]++;
			}
		}
		for(j=0;j<52;j++)
		{
			if(arr[j]%2==0)
			{
				sum=sum+(arr[j]/2) ;
			}
			else
			{
				sum=sum+(arr[j]/2)+1;
			}
		}
		printf("%d\n",sum);
		sum=0;
		T--;
	}
return 0;
}
