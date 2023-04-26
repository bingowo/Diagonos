#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI acos(-1)
struct data{
	double x;
	double y;
	double p;
	double rad;
};
struct data d[10000];
int cmp(const void*a,const void*b)
{
	struct data da=*(struct data*)a;
	struct data db=*(struct data*)b;
	if(da.rad !=db.rad ){
		if(da.rad>db.rad )return 1;
		else return -1;
	}
	else{
		if(da.p >db.p )return -1;
		else return 1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			scanf("%lf",&d[j].x );
			scanf("%lf",&d[j].y );
			double z=d[j].x *d[j].x +d[j].y *d[j].y ; 
			d[j].p =sqrt(z);
			if(d[j].x>=0&&d[j].y>=0)d[j].rad=atan(d[j].y/d[j].x );
			if(d[j].x<0)d[j].rad=PI+atan(d[j].y/d[j].x);
			if(d[j].x>=0&&d[j].y<0)d[j].rad=2*PI+atan(d[j].y/d[j].x);
	    }
		qsort(d,N,sizeof(d[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N;k++)
		{
			printf("(%.4lf,%.4lf)\n",d[k].p ,d[k].rad );
		}
	}
	return 0;
}