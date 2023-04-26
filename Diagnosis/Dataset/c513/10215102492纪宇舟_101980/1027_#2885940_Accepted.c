#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
const double PI = 3.1415926;
typedef struct{
	double P,L;
}AG;
int cmp(const void* a,const void* b)
{
	AG x=*(AG*)a;AG y=*(AG*)b;
	if(x.P<y.P)return -1;
	else if(x.P==y.P)
	{
		if(x.L>y.L)return -1;
		else return 1;
	}
	else return 1;
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	AG ag[1005];
	while(T--)
	{
		int n;scanf("%d",&n);
		double x,y;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x,&y);
			ag[i].L=sqrt(x*x+y*y);
			ag[i].P=atan2(y,x);
			if(ag[i].P<0)ag[i].P+=2*PI;
		}
		qsort(ag+1,n,sizeof(AG),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)printf("(%.4lf,%.4lf)\n",ag[i].L,ag[i].P);
	}
	return 0;
}