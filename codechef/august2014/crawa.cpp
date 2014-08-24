#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		if((x%2)&&(y>=(-1*(x-1)) && y<=x+1))
		{
			printf("%s\n","YES");
		}
		else if((!(y%2))&&((x<= y-1) && (x >= -y)) )
		{
			printf("%s\n","YES");
		}
		else if((!(x%2))&&(y <= -x && y >= x ))
		{
			printf("%s\n","YES");
		}
		else if((!(y%2)) &&(x >= y && x<= -y+1))
		{
			printf("%s\n","YES");
		}
		else
		{
			printf("%s\n","NO");
		}
	}
return 0;
}
