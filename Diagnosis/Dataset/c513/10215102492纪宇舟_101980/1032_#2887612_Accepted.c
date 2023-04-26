#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	int L,num[51];
}NUM;
int cmp(const void* a,const void* b)
{
	NUM x=*(NUM*)a;NUM y=*(NUM*)b;
	int i=1,j=1;
	while(i<=x.L&&j<=y.L)
	{
		if(x.num[i]>y.num[j])return -1;
		if(y.num[i]>x.num[j])return  1;
		if(i==x.L)return  1;
		if(j==y.L)return -1;
		i++;j++;
	}
}
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	NUM a[1001];
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			a[i].L=0;
			while(scanf("%d",&a[i].num[a[i].L+1])&&a[i].num[a[i].L+1]!=-1)a[i].L++;
		}
		qsort(a+1,n,sizeof(NUM),cmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].L;j++)
			printf("%d ",a[i].num[j]);
			printf("\n");
		}
	}
	return 0;
}