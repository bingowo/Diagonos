#include <stdio.h>
#include <string.h>
typedef struct { int cnt; int num[505];}BIGINT;

BIGINT big_sub(BIGINT a,BIGINT b)//a-b
{
	for(int i=b.cnt-1;i>=0;i--)
	{
		//temp=a->num[i] - b->num[i];
		if(a.num[i] - b.num[i]<0)//要借位
		{
			int x=i+1;
			while(a.num[x]==0)
				a.num[x]=9,x++;
			a.num[x]--;
			if(x == a.cnt-1)
				a.cnt--;
			a.num[i] = a.num[i] - b.num[i] + 10;
		}
		else
			a.num[i] -= b.num[i];
	}
	while(a.num[a.cnt-1]==0)
		a.cnt--;
	return a;
}
BIGINT trans(char s[])
{
	BIGINT a={0,{0}};
	int len=strlen(s);
	for(int i=len-1;i>=0;i--)
	{
		a.num[a.cnt++]=s[i]-'0';
	}
	return a;
}
int main()
{
	char s1[505],s2[505];
	while(scanf("%s %s",s1,s2)!=EOF)
	{
		BIGINT a = trans(s1),b = trans(s2);
		BIGINT c = big_sub(a,b);
		
		for(int i=c.cnt-1;i>=0;i--)
			printf("%d",c.num[i]);
		putchar('\n');
	}
}