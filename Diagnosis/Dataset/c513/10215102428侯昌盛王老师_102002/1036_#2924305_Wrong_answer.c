#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct w{
	long long x,y;
	unsigned long long s;
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
		scanf("%lld %lld",&a[i].x,&a[i].y);
		long long x1=a[i].x,y1=a[i].y;
		if(a[i].x<0) x1=-a[i].x;
		if(a[i].y<0) y1=-a[i].y;
		a[i].s=x1+y1;
	//	printf("%llu\n",a[i].s);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	unsigned long long k;
	long long x2,y2;
	x2=(a[0].x-a[1].x);
	y2=(a[0].y-a[1].y);
	if(x2<0) x2=-(a[0].x-a[1].x);
	if(y2<0) y2=-(a[0].y-a[1].y);
	k=x2+y2;
	printf("%llu\n",k);
	int j=0,sum=0;
	for(j;j<n-1;j++)
	{
		x2=(a[j].x-a[j+1].x);
		y2=(a[j].y-a[1+j].y);
		if(x2<0) x2=-(a[j].x-a[1+j].x);
		if(y2<0) y2=-(a[j].y-a[1+j].y);
		k=x2+y2;
		if(k%2==0) break;
		int m=0;
		for(m;;m++)
		{
			if(pow(2,m+1)-1>k){
				sum+=m;
				break;
			}
		}
	}	
	printf("%lld",sum);
	
	
	
	
	return 0;
}