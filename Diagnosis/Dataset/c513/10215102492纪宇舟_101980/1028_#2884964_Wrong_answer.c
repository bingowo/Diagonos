#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp1(const void* a,const void* b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;
	else return 1;
}
int cmp2(const void* a,const void* b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return 1;
	else return -1;
}
int main()
{
	int n=0,a[105];
	char c,s[100005];
	scanf("%c\n",&c);gets(s);
	int len=strlen(s);
	int x=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]!=' ')x=x*10+(s[i]-'0');
		if(s[i]==' '||i==len-1)
		{
			a[++n]=x;x=0;
		}
	}
	if(c=='A')qsort(a+1,n,sizeof(int),cmp1);
	else qsort(a+1,n,sizeof(int),cmp2);
	int last=1001;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==last)continue;
		last=a[i];printf("%d",last);
		if(i!=n)printf(" ");
	}
	return 0;
}