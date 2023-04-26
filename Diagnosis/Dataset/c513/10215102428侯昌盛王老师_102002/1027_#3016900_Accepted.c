#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int cmp(const void*a,const void*b)
{
	double *p,*q;
	const double eps=1e-10;
	p=(double*)a;q=(double*)b;
	if(*p>*q+eps) return 1;
	else if(*q>*p+eps) return -1;
	else if(fabs(*p-*q)<eps){
		p++;q++;
		//printf("%f %f\n",*p,*q);
		if(*p>*q+eps) return -1;
		else if(*q>*p+eps) return 1;
	}
}
int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int n,i,h=0;
		scanf("%d",&n);
		double a[1001][2]={0};
		for(i=0;i<n;i++)
		{
			double x,y;
			scanf("%lf %lf",&x,&y);
			double ans;
			double len,k;
			k=x*x+y*y;
			len=sqrt(k);
			if(y>=0) ans=acos(x/len);
			else{
				ans=acos(-x/len)+PI;
				
			}
			a[h][0]=ans;
			a[h++][1]=len;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",e);
		for(i=0;i<n;i++)
		{
			printf("(%.4f,%.4f)\n",a[i][1],a[i][0]);
		}
	}
	return 0;
} 