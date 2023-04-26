#include<stdio.h>
#include<stdlib.h>
typedef struct{long long R,H,sc,sd,st;int flag=0;} col;
int cmp1(const void* a,const void* b)
{
	col p1=*(col*)a,p2=*(col*)b;
	if(p1.st>p2.st)return -1;
	else return 1;
}
int cmp2(const void* a,const void* b)
{
	col p1=*(col*)a,p2=*(col*)b;
	if(p1.sd>p2.sd)return -1;
	else return 1;
}
int cmp3(const void* a,const void* b)
{
	col p1=*(col*)a,p2=*(col*)b;
	if(p1.sc>p2.sc)return -1;
	else return 1;
}
int main()
{
	int n,m,i,j,k;scanf("%d%d",&n,&m);
	col a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].R,&a[i].H);
		a[i].sc=2*a[i].R*a[i].H;a[i].sd=a[i].R*a[i].R;
		a[i].st=a[i].sc+a[i].sd;
	}
	//for(k=0;k<n;k++)printf("%lld %lld %lld %lld %lld\n",a[k].H,a[k].R,a[k].sc,a[k].sd,a[k].st);
	qsort(a,n,sizeof(col),cmp1);
	long long ans=a[0].st;
	a[0].flag=1;
	qsort(a,n,sizeof(col),cmp2);
	for(i=0;i<n;i++)
	{
		if(a[i].flag==1)break;
	}
	col b[n-i-1];
	for(++i,j=0;i<n;i++,j++)
	{
		b[j]=a[i];
	}
	qsort (b,j,sizeof(col),cmp3);
	for(j=0;j<m-1;j++)
	{
		ans+=b[j].sc;
	}
	printf("%lld",ans);
	return 0;
}