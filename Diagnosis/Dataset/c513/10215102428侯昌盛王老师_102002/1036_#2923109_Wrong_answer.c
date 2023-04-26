#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct w{
	double x,y,s;
};

int cmp(const void*a,const void*b)
{
	struct w *q,*p;
	q=(struct w*)a;
	p=(struct w*)b;
	if((q->s)>(p->s)) return -1;
	else{
		if((q->s)<(p->s)) return 1;
		else return 0;
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	struct w a[n];
	for(i=0;i<n;i++){
		scanf("%lf %lf",&a[i].x,&a[i].y);
		a[i].s=fabs(a[i].x)+fabs(a[i].y);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	double k;
	k=fabs(a[0].x-a[1].x)+fabs(a[0].y-a[1].y);
	printf("%.0lf\n",k);
	int j=0;
	double sum=0;
	for(j;j<n-1;j++)
	{
		k=fabs(a[j].x-a[j+1].x)+fabs(a[j].y-a[j+1].y);
		double m=0,tes=1.0;
		for(m;;m++)
		{
			
			if(fmod(k,2)==0){
				tes=fmod(k,2);
				break;
			}
			double z=pow(2,m+1)-1;
			if((z>=k) && ((z-k)==1 || fmod(z-k,2)==0)){
				sum+=(m+1);
				break;
			}
			else if((z>k) && fmod(z-k,2)!=0){
				tes=0;
				break;
			}
		}
		if(tes==0) break;
	}	
	printf("%.0lf",sum);
	
	
	
	
	return 0;
}