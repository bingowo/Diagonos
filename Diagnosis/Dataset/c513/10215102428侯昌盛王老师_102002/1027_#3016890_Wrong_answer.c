#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int cmp(const void*a,const void*b)
{
	double *p,*q;
	p=(double*)a;q=(double*)b;
	if((*p-*q)>0.000000001) return 1;
	else if((*p-*q)<0.000000001) return -1;
	else{
		p++;q++;
		if((*p-*q)>=0.000001) return -1;
		else return 1;
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
		qsort(a,h,sizeof(a[0]),cmp);
		printf("case #%d:\n",e);
		for(i=0;i<h;i++)
		{
			printf("(%.4f,%.4f)\n",a[i][1],a[i][0]);
		}
	}
	return 0;
} 