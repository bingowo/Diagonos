#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{
	long long num;
	int h;
}a[10010];
int mycmp(const void*aa,const void*bb)
{
	struct node a = *(struct node*)aa;
	struct node b = *(struct node*)bb;
	if(a.h == b.h)
	{
		if(a.num > b.num) return 1;
		else return -1;
	}
	else
	{
		if(a.h < b.h) return 1;
		else return -1;
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		char s[20];
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			a[i].num = atoll(s);
			if(s[0]=='-') a[i].h = s[1]-'0';
			else a[i].h = s[0]-'0';
		}
		qsort(a+1,n,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=1;i<=n;i++) printf("%lld ",a[i].num);
		putchar('\n');
	}
	return 0;
}