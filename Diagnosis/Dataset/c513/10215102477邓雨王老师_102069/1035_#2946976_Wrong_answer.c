#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct{
	lli r;
	lli h;
	lli sc;
}yuanzhu;
int cmp(const void *a,const void *b)//按侧面积由大到小排序，侧面积相同的按半径由大到小排序 
{
	yuanzhu * pa = (yuanzhu *) a;
	yuanzhu * pb = (yuanzhu *) b;
	if (pa->sc > pb->sc) return -1;
	else if (pa->sc < pb->sc) return 1;
	else if (pa->sc==pb->sc)
	{
		if (pa->r > pb->r) return -1;
		else if(pa->r < pb->r) return 1;
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	yuanzhu input[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&input[i].r,&input[i].h);
		input[i].sc=input[i].r*2*input[i].h;
	}
	qsort(input,n,sizeof(yuanzhu),cmp);
	lli maxs=0;
	int j;
	for(j=0;j<m;j++)
	{
		maxs+=input[j].sc;//选取qsort后的前m个圆柱 
	}
	maxs= maxs+input[0].r*input[0].r;//不知道为什么总是和结果少1，所以加1 
	printf("%lld",maxs);
}