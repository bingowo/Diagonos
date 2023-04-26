#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
void trans(double x,double y,double *m)
{
	double x1,y1;
	x1=pow(x,2);
	y1=pow(y,2);
	double sum1=x1+y1;
	double sum,k,c;
	sum=pow(sum1,0.5);
	k=y/sum;
	c=asin(k);
	c=fabs(c);
	if(x<0 && y>=0) c=c+PI/2;
	//if(x<0 && y>0) c=c+PI/2;
	//else if(x<0 && y==0) c=c+PI;
	else if(x<=0 && y<0) c=c+PI;
	else if(x>0 && y<0) c=c+(3*PI)/2;
	m[0]=c;
	m[1]=sum;
	
}

int cmp(const void*a,const void*b)
{
	double *q,*p;
	q=(double*)a;p=(double*)b;
	if(*q==*p) {
		p++;q++;
		if(*q<*p) return -1;
		else return 1;
		
	} 
	else{
	
		if(*q<*p) return -1;
		else return 1;
		
	}
}


int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		int n,j;
		double m[1000][10];
		scanf("%d",&n);
		for(j=0;j<n;j++){
		
			double x,y;
			scanf("%lf %lf",&x,&y);
			//x=fabs(x);y=fabs(y);
			trans(x,y,m[j]);
		}
		qsort(m,n,sizeof(m[0]),cmp);
		int u=0;
		printf("case #%d:\n",i);
		for(u;u<n;u++)
		{
			
			printf("(%.4lf,%.4lf)\n",m[u][1],m[u][0]);
		}
	}
	return 0;
}