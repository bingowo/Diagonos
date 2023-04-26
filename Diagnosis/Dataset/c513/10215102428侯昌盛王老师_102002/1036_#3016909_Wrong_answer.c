#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	long long x,y;
	long long d;
}ar;
int cmp(const void*a,const void*b)
{
	ar *p,*q;
	p=(ar*)a;q=(ar*)b;
	if((p->d)>(q->d)) return -1;
	else if((p->d)<(q->d)) return 1;
	else{
		if((p->x)<(q->x)) return -1;
		else if((p->x)>(q->x)) return 1;
		else{
			if((p->y)<=(q->y)) return -1;
			else return 1;
		}
	}
}
int main()
{
	int n,i,k=0;
	scanf("%d",&n);
	ar ar[101];
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&ar[k].x,&ar[k].y);
		ar[k].d=llabs(ar[k].x)+llabs(ar[k].y);
		k++;
	}
	qsort(ar,n,sizeof(ar[0]),cmp);
	long long k1;
	k1=llabs(ar[0].x-ar[1].x)+llabs(ar[0].y-ar[1].y);
	printf("%lld\n",k1);
	i=0;
	int sum=0;
	//printf("%lld\n",ar[0].d/2);
	long long sd;
	sd=llabs(ar[0].x-ar[1].x)+llabs(ar[0].y-ar[1].y);
	while(sd!=2&&(sd%2!=0||(sd/2)%2!=0)&&i<n-1)
	{
		int m;
		
		m=(int)sqrt(sd*1.0)+1;
		sum+=m;
		i++;
		sd=llabs(ar[i].x-ar[i+1].x)+llabs(ar[i].y-ar[i+1].y);
	}
	printf("%d\n",sum);
	
	return 0;
}