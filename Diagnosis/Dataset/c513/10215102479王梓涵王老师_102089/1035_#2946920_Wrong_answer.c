#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct{
	lli r;
	lli h;
	lli sc;
}yuanzhu;

int cmp(const void *a,const void *b)
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
	lli maxs;
	int j;
	for(j=0;j<m;j++)
	{
		maxs+=input[j].sc;
	}
	
	maxs= maxs+input[0].r*input[0].r+1;
	printf("%lld",maxs);
	return 0;
}