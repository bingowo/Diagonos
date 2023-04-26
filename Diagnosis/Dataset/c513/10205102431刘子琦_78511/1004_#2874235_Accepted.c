#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solveint(int n)
{
	int i=sizeof(n);
	unsigned char *c=(unsigned char*)&n;
	while(i>0)
	{
		printf("%02x ",*c++);
		i--;
	}	
	printf("\n");
} 
void solvedouble(double n)
{
	double i=sizeof(n);
	unsigned char *c=(unsigned char*)&n;
	while(i>0)
	{
		printf("%02x ",*c++);
		i--;
	}	
	printf("\n");	
}
int main()
{
	char a[31];
	while(scanf("%s",a)!=EOF)
	{
		if(strchr(a,'.')!=0)solvedouble(atof(a));
		else solveint(atoi(a));
	}	
	return 0;
}