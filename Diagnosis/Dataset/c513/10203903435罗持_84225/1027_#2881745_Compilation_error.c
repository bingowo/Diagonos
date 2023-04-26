#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct ans
{
	double p,o;
};
int mycmp(const ans&a,const ans&b)
{
	if(abs(a.o-b.o)<=10e-8) return -a.p+b.p;
	return a.o-b.o;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		struct ans a[n];
		for(int i=0;i<n;i++)
		{
			double x,y;
			scanf("%f %f",&x,&y);
			a[i].p = sqrt(x*x +y*y);
			if(y>=0) a[i].o = acos(x/a[i].p);
			else a[i].o = 2*acos(-1) - acos(x/a[i].p);
		}
		qsort(a,n,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=0;i<n;i++)
			printf("(%.4f,%.4f)\n",a[i].p,a[i].o);
	}
	return 0;
}