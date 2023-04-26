#include <stdio.h>
#include <string.h>
char s[100];
int check(int l,int r)
{
	if(l==r) return 1;
	for(int i=l+1;i<=r;i++)
	{
		if(s[i]==s[i-1]) return 0;
	}
	return 1;
} 
int main(void)
{
	scanf("%s",s);
	int len = strlen(s);
	int res = 0;
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(check(i,j) && j-i+1>res)
			{
				res = j-i+1;
			}
		}
	}
	printf("%d",res);
	return 0;
} 