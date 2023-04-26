#include<stdio.h>
#include<stdlib.h>
int is_int(const char *s)
{
	while(*s++)if(*s=='.')return -1;
	return 1;
}
void solveint(const void* a,int n)
{
	unsigned char* ax=(unsigned char*)a;
	while(n--)
	{
		printf("%02x",*ax++);
	}
	printf("\n");
}
void solvedouble(const void* a,int n)
{
	unsigned char* ax=(unsigned char*)a;
	while(n--)
	{
		printf("%02x",*ax++);
	}
	printf("\n");
}
int main()
{
	char s[31];
	while((scanf("%s",s))==1)
	{
		char *p=s;
		if(is_int(p)==1)
		{
			int ans=atoi(s);
			int n=sizeof(ans);
			solveint(&ans,n);
		}
		else
		{
			double ans=atof(s);
			int n=sizeof(ans);
			solvedouble(&ans,n);
			
		}
	}
	return 0;
}