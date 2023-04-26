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
	long long int hrm=d[0].hr;
	for(i=0;i<m;i++)
	{
		if(d[i].R>RM)
		{
			RM=d[i].R;
			HM=d[i].H;
		}
		if(d[i].hr<hrm)
		{
			hrm=d[i].hr;
		}
		s1+=d[i].hr;
	}
	s2=RM*RM;
	long long int ans=s1*2+s2;
	long long int temp=0;
	for(i=m;i<n;i++)
	{
		long long t=d[i].hr*2+d[i].R*d[i].R;
		if(d[i].R>RM&&t>(2*hrm+RM*RM)&&t>temp)
		{
			temp=d[i].hr*2+d[i].R*d[i].R;
		}
	}
	if(temp>0)
	{
		ans=ans-(2*hrm+RM*RM)+temp;
	}
	printf("%lld",ans);
 } 