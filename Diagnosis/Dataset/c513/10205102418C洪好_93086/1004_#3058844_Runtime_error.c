#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char x[50];
	int j;
	while(scanf("%s",x)!=EOF)
	{
		if(strchr(x,'.')!=NULL)
		{
			double d=atof(x);//把字符串转换成浮点数
			unsigned char *p=0;
			*p=(unsigned char)&d;
			for(j=0;j<8;j++)
			{
				printf("%02x ",*p++);
			}
			printf("\n");
		}
		else
		{
			int i=atoi(x);
			unsigned char *p=0;
			*p=(unsigned char)&i;
			for(j=0;j<4;j++)
			{
				printf("%02x ",*p++);
			}
			printf("\n");
		}
	}
	return 0;
} 