#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define  PI  3.14159265
typedef struct{double x;double y;double dis;double angle;} point;
int cmp(const void* a,const void* b)
{
	point *p1,*p2;
	p1=(point*)a;p2=(point*)b;
	if(p1->angle>p2->angle)return 1;
	else if(p1->angle<p2->angle)return -1;
	else
	{
		if(p1->dis>p2->dis)return -1;
		else return 1;
	}
}
int main()
{
	int N,n;scanf("%d",&N);
	int i,j;
	for(i=0;i<N;i++)
	{
		scanf("%d",&n);
		point p[n];
		for(j=0;j<n;j++)
		{
			scanf("%lf%lf",&p[j].x,&p[j].y);
			p[j].dis=sqrt(p[j].x*p[j].x+p[j].y*p[j].y);
			p[j].angle=atan2(p[j].y,p[j].x);
			if(p[j].angle<0)p[j].angle=2*PI+p[j].angle;
		}
		qsort(p,n,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)printf("(%.4f,%.4f)\n",p[j].dis,p[j].angle);
	}
	return 0;
}