#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int tab[1005];
typedef struct{
	int num,sig;
}NUM;
int cmp(const void* a,const void* b)
{
	NUM x=*(NUM*)a;NUM y=*(NUM*)b;
	if(x.sig==y.sig)return x.num-y.num;
	else return x.sig-y.sig;
}
int main()
{
	int n,m,x;
	NUM a[1005];
	memset(tab,0,sizeof(tab));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tab[x]=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i].num);
		if(tab[a[i].num])a[i].sig=tab[a[i].num];
		else a[i].sig=1005;
	}
	qsort(a+1,m,sizeof(NUM),cmp);
	for(int i=1;i<=m;i++)printf("%d ",a[i].num);
	return 0;
}