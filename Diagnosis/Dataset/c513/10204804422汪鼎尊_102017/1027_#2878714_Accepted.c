#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a1,const void *b1)
{
	double *a=(double*)a1,*b=(double*)b1;
	if(*(a+1)>*(b+1))return 1;
	if(*(a+1)<*(b+1))return -1;
	if(*a>*b)return -1;
	if(*a<*b)return 1;
	return 0;
}

int main()
{
	int i;
	double j,k;
	int len=0;
	int c,cases;
	double pts[1000][2];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			scanf("%lf %lf",&j,&k);
			pts[i][0]=sqrt(j*j+k*k);
			pts[i][1]=atan2(k,j);
			if(pts[i][1]<0)pts[i][1]+=2*3.1415926535;
		}
		qsort(pts,len,2*sizeof(double),cmp);
		printf("case #%d:\n",c);
		for(i=0;i<len;i++)printf("(%.4lf,%.4lf)\n",pts[i][0],pts[i][1]);
	}
	return 0;
}