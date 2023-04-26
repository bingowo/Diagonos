#include<stdio.h>
#include<stdlib.h>
struct data{
	int H;
	int R;
	int hr;
}d[1001];
int cmp(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return d.hr-c.hr;
 } 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i].R);
		scanf("%d",&d[i].H);
		d[i].hr=d[i].H*d[i].R;
	}
	qsort(d,n,sizeof(d[0]),cmp);
	int HM=d[0].H,RM=d[0].R;
	long long int s1=0,s2=0;//s1为侧面积，s2为最大底面积 
	for(i=0;i<m;i++)
	{
		if(d[i].R>RM)
		{
			RM=d[i].R;
			HM=d[i].H;
		}
		s1+=d[i].hr;
	}
	s2=RM*RM;
	for(i=m;i<n;i++)
	{
		if(d[i].R>RM&&d[i].hr>=HM*RM)
		{
			s1=s1-HM*RM+d[i].hr;
			s2=d[i].R*d[i].R;
		}
	}
	long long int ans=s1*2+s2;
	printf("%lld",ans);
 } 