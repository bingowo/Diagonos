#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[1001],ans[2022];
int main()
{
	scanf("%s",s);
	int n=strlen(s),l=1000,r=l;
	ans[l]=toupper(s[0]);
	for(int i=1;i<n;i++)
	{
		s[i]=toupper(s[i]);
		if(s[i]>ans[l])ans[--l]=s[i];
		else ans[++r]=s[i];
	}
	for(int i=l;i<=r;i++)printf("%c",ans[i]);
	return 0;
}