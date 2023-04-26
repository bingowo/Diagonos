#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char s[2000];
int main()
{
	unsigned char *p=0;
	int n;
    while(scanf("%s",s)!=EOF)
    {
    	if(strchr(s,'.')==NULL)
		{
			int a=atoi(s);
			int *t=&a;
			p=(unsigned  char *)t;
			for(int i=0;i<4;i++)
				printf("%02x ",*(p+i));
		}	
		else
		{
			double b=atof(s);
			double *t=&b;
			p=(unsigned char *)t;
			for(int i=0;i<8;i++)
				printf("%02x ",*(p+i));
		}
		printf("\n");
	}
	return 0;
}