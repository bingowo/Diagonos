#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10000
char anti(char ats[])
{
	for(int i=0;i<strlen(ats);i++)
	{
		if(ats[i]=='0')
		{
			ats[i]='1';
		}
		else
		{
			ats[i]='0';
		}
	}
}
int main()
{
	int i;
	scanf("%d",&i);
	char s[M]={0};
	s[0]='0';
	s[1]='1';
	for(int j=2;j<=i;j++)
	{
		char ats[M]={0};
		strcpy(ats,s);
		anti(ats);
		strcat(s,ats);
	}
	if(i==0)
	{
		printf("0");
		return 0;
	}
	printf("%s",s);
}