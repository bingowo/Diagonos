#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
	char c;
	double weigh;
	int cnt_da;
	int cnt_xiao;
}a[30];
int mycmp(const void*x,const void*y)
{
	struct node xx = *(struct node*)x;
	struct node yy = *(struct node*)y;
	if(xx.weigh > yy.weigh) return -1;
	else return 1;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		for(int i=0;i<26;i++) 
		{
			scanf("%lf",&a[i].weigh);
			a[i].cnt_da = 0;
			a[i].cnt_xiao = 0;
		}
		char s[200];
		scanf("%s",s);
		int n = strlen(s);
		for(int i=0;i<n;i++)
		{
			if(s[i]>='A' && s[i]<='Z') a[toupper(s[i])-'A'].cnt_da++;
			else a[toupper(s[i])-'A'].cnt_xiao++;
			a[toupper(s[i])-'A'].c = s[i];
		}
		qsort(a,26,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=0;i<26;i++)
		{
			for(int j=1;j<=a[i].cnt_xiao;j++) printf("%c",tolower(a[i].c));
			for(int j=1;j<=a[i].cnt_da;j++) printf("%c",toupper(a[i].c));
		}
		putchar('\n');
	}
	return 0;
}