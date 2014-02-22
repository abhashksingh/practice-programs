const  long long radix_base=10;

char *strrev(char *str)
{
	char c, *front, *back;
	for(front=str,back=str+strlen(str)-1;front < back;front++,back--)
	{
		c=*front;*front=*back;*back=c;
	}
	return str;
}

char *itoa(long long v, char *buff)
{
	static char table[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *p=buff;
	unsigned long long n = (v < 0 && radix_base == 10)? -v : (unsigned long long) v;
	while(n>=radix_base)
	{
		*p++=table[n%radix_base];
		n/=radix_base;
	}
	*p++=table[n];
	if(v < 0 && radix_base == 10) *p++='-';
	*p='\0';
	return strrev(buff);
}
