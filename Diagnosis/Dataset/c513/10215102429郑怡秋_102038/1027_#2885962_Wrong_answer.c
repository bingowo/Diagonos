#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 
#define PI 3.14159265
typedef struct{
	double a;double b;
	double c;double d;
}QWQ;
double two(double a)
{
	return a*a;
}
int cmp(const void*a,const void*b)
{
	QWQ* p1=(QWQ*)a;QWQ* p2=(QWQ*)b;
	if((p1->d)>(p2->d)) return 1;
	else if((p1->d)<(p2->d)) return -1;
	else
	{
		if((p1->c)>(p2->c)) return -1;
		else return 1;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		QWQ q[2010];
		for(int j=0;j<n;j++)
		{
			scanf("%lf%lf",&q[j].a,&q[j].b);
		}
		for(int j=0;j<n;j++)
		{
			q[j].c=sqrt(two(q[j].a)+two(q[j].b));
			if(q[j].a==0)
			{
				if(q[j].b>0) q[j].d=PI/2;
				else if(q[j].b<0) q[j].d=3*PI/2;
			}
			else if(q[j].b==0)
			{
				if(q[j].a>0) q[j].d=0;
				else if(q[j].a<0) q[j].d=PI;
			}
			else if(q[j].a>=0&&q[j].b>=0)
			{
				q[j].d=atan(q[j].a/q[j].b);
			}
			else if(q[j].a>=0&&q[j].b<=0)
			{
				q[j].d=atan((-1)*q[j].a/q[j].b)+3*PI/2;
			}
			else if(q[j].a<=0&&q[j].b>=0)
			{
				q[j].d=PI-atan((-1)*q[j].a/q[j].b);
			}
			else if(q[j].a<=0&&q[j].b<=0)
			{
				q[j].d=3*PI/2-atan(q[j].a/q[j].b);
			}
		}
		qsort(q,n,sizeof(QWQ),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		{
			printf("(%.4f,%.4f)\n",q[j].c,q[j].d);
		}
		
	}	
	return 0;
}