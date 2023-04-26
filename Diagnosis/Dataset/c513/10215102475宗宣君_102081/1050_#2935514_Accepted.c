#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int num(char *a,char *b)
{
	int i,j;
	for(i = 0;i<=strlen(b)-strlen(a);i++)
	{int n = 0;
	for(j = 0;j<strlen(a);j++)
	{
	if(a[j]!=b[i+j]) break;
	n++;}
	if(n==strlen(a)) return i;
    }
    return -1;
}
int num1(char *a,char *b)
{
	int i,j;
	for(i = strlen(b)-1;i>=0;i--)
	{int n = 0;
	for(j = 0;j<strlen(a);j++)
	{
	if(a[j]!=b[i+j]) break;
	n++;}
	if(n==strlen(a)) return i;
    }
    return -1;
}
int main()
{
	int T,i;
	scanf("%d\n",&T);
	for(i = 0;i<T;i++)
	{
		int res = 0;
		char s1[81],s2[81],s3[81];
		scanf("%s %s %s",s1,s2,s3);
		if(strlen(s1)>strlen(s3)||strlen(s2)>strlen(s3)) res = 0;
		else {int a1 = num(s1,s3),a2 = num1(s1,s3),b1 = num(s2,s3),b2 = num1(s2,s3);
		if(a1==-1||b1==-1) res = 0;
		else if(a1==0&&a2==0&&b1==0&&b2==0) res = 0;
		else
		{
			int m,n;
			m = a2-b1-strlen(s2);
			n = b2-a1-strlen(s1);
			res = m>n?m:n;
		}}
		printf("case #%d:\n%d\n",i,res);
	}
	return 0;
}
