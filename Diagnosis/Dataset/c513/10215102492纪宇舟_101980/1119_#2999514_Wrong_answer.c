#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	double h,v,timeleft;
}CAR;
int cmp(const void *a,const void *b)
{
	CAR x=*(CAR*)a;CAR y=*(CAR*)b;
	if(x.h>y.h)return -1;return 1;
}
int main()
{
	CAR a[1005];
	int n;double d,toltime=0.0;
	scanf("%lf",&d);scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].h,&a[i].v);
	qsort(a+1,n,sizeof(CAR),cmp);
	a[0].h=d;a[0].v=10001.0;a[0].timeleft=0;
	int sig=1,pos=1;
	while(sig)
	{
		double mint=-1.0;sig=0;
		for(int i=pos;i<=n;i++)
		{
			if(a[i].v>a[i-1].v)
			{
				double T=(a[i-1].h-a[i].h)/(a[i].v-a[i-1].v);
				if(T*a[i].v>d-a[i].h)continue;
				if(mint<0||T<mint)mint=T;sig=1;
			}
		}
		if(sig==0)break;
		toltime+=mint;
		for(int i=pos;i<=n;i++)
		{
			a[i].h+=a[i].v*mint;
			if(a[i].h==a[i-1].h&&pos<=i-1)a[i].v=a[i-1].v;
			if(a[i].h>=d)pos=i+1;
		}
	}
	toltime+=(d-a[n].h)/a[n].v;
	printf("%.6lf",d/toltime);
	return 0;
}