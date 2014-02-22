/*A monochrome screen is stored as a single array of bytes,allowing eight consecutive pixels to be stored in one byte.The screen has width
 * w,where w is divisible by 8.The height of screen ,of course can be derived from the length of the array and width . Implement a function
 * drawHorizontalLine(byte[] screen,int width,int x1,int x2,int y) which draws a horizontal line from (x1,y) to (x2,y)*/
#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
	int scr_size,width,x1,x2,y;
	cout<<"Enter Screen size: ";
	cin>>scr_size;
	cout<<"Enter width: ";
	cin>>width;
	cout<<"Enter x1,x2 and y : ";
	cin>>x1;
	cin>>x2;
	cin>>y;
	uint8_t screen[scr_size];
	for(int i=0;i<scr_size;i++)
	{
		screen[i]=0;
	}
	int start_offset = x1%8;
	int first_full_byte = x1/8;
	if(start_offset!=0)
	{
		first_full_byte++;
	}
	int end_offset = x2%8;
	int last_full_byte = x2/8;
	if(end_offset !=7)
	{
		last_full_byte--;
	}
	//Set full bytes
	for(int b=first_full_byte;b<=last_full_byte;b++)
	{
		screen[(width/8)*y +b]=(uint8_t)0xFF;
	}
	//Create masks for start and end of line
	uint8_t start_mask = (uint8_t)(0xFF>>start_offset);
	uint8_t end_mask = (uint8_t)~(0xFF>>(end_offset+1));
	//set start and end of line
	if((x1/8)==(x2/8))
	{
		//x1 and x2 are in the same byte
		uint8_t mask = (uint8_t)(start_mask & end_mask);
		screen[(width/8)*y+first_full_byte-1]|=mask;
	}
	else
	{
		if(start_offset!=0)
		{
			int byte_number = (width/8)*y+first_full_byte-1;
			screen[byte_number]|=start_mask;
		}
		if(end_offset!=7)
		{
			int byte_number = (width/8)*y+first_full_byte-1;
			screen[byte_number]|=end_mask;
		}
	}
return 0;
}
