#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	char id[15];
	int score;
}a[1000];
int mf[15] = {0};
int mycmp(const void*a,const void*b)
{
	struct node aa = *(struct node*)a;
	struct node bb = *(struct node*)b;
	if(aa.score == bb.score) return strcmp(aa.id,bb.id);
	else return bb.score-aa.score;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n,m,g;
		scanf("%d %d %d",&n,&m,&g);
		for(int i=1;i<=m;i++) scanf("%d",&mf[i]);
		for(int i=1;i<=n;i++)
		{
			a[i].score = 0;
			scanf("%s",a[i].id);
			int t;
			scanf("%d",&t);
			for(int j=1;j<=t;j++)
			{
				int hao;
				scanf("%d",&hao);
				a[i].score += mf[hao];
			}
		} 
		qsort(a+1,n,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		int cnt = 0;
		for(int i=1;i<=n;i++) 
			if(a[i].score >= g) cnt++;
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%s %d\n",a[i].id,a[i].score);
	}
	return 0;
}