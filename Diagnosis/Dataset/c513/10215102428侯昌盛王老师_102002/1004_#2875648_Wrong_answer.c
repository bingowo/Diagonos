#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void n(int n);
void d(double d);
int main()
{
	char s[31];
	while(~scanf("%s",s))
	{
		if(strchr(s,'.')==0) n(atoi(s));
		else d(atof(s));
	}
	return 0;
}
void n(int n)
{
	int c=sizeof(n);
	unsigned char*p=(unsigned char*)&n;
	while(c--) printf("%02x ",*p);
	printf("\n");
}
void d(double d)
{
	int c=sizeof(d);
	unsigned char*p=(unsigned char*)&d;
	while(c--) printf("%02x ",*p++);
	printf("\n");
}