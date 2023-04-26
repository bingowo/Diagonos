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
			n=sizeof(a);
			int *t=&a;
			p=(unsigned  char *)t;
		}	
		else
		{
			double b=atof(s);
			n=sizeof(b);
			double *t=&b;
			p=(unsigned char *)t;
		}
		for(int i=0;i<n;i++)
			printf("%02x ",*p++);
		printf("\n");
	}
	return 0;
}