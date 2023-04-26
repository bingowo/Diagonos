#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	long long x,y;
	unsigned long long d;
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
void add(int*a,int*b)
{
	int i=30,carry=0;
	for(i;i>=0;i--)
	{
		a[i]=a[i]+b[i]+carry;
		carry=a[i]/10;
		a[i]=a[i]%10;
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
	int num[101][31];
	int j=0;
	for(j;j<n-1;j++)
	{
		i=30;
		unsigned long long x1,y1;
		x1=llabs(ar[j].x-ar[j+1].x);y1=llabs(ar[j].y-ar[j+1].y);
		while(x1!=0)
		{
			num[j][i]=x1%10;
			x1/=10;
			i--;
		}
		i=30;
		while(y1!=0)
		{
			num[j+1][i]=y1%10;
			y1/=10;
			i--;
		}
		add(num[j],num[j+1]);
	}
	int p=0,flag=0;
	for(p;p<31&&num[0][p]==0;p++);
	if(p==31) goto a;
	for(p;p<31;p++) 
	{
		printf("%d",num[0][p]);
		flag=1;
	}
	a:if(flag==0) printf("0");
	printf("\n");
	i=0;
	int sum=0;
	//printf("%lld\n",ar[0].d/2);
	unsigned long long sd;
	flag=0;
	if(ar[0].x==ar[1].x&&ar[0].y==ar[1].y) {
		sd=llabs(ar[0].x-ar[1].x)+llabs(ar[0].y-ar[1].y);
		flag=1;
	}
	else sd=llabs(ar[0].x-ar[1].x)-1+llabs(ar[0].y-ar[1].y);
	//printf("k=%llu\n",sd);
	
	while(sd!=1&&sd+1!=0&&((sd==-1&&i==0)||(sd+1)%2!=0)&&i<n-1)
	{
		int m=0;
		//printf("k=%llu\n",sd);
		
		//printf("h\n");
		//printf("h\n");
		if(sd==0&&flag==0) sd++;
		//printf("%llu\n",sd);
		while(sd!=0) {
			sd/=2;
			m++;
		}
		//printf("m=%d\n",m);
		//printf("h\n");
		sum+=m;
		//printf("%d %llu\n",m,sd);
		i++;
		if(ar[i].x==ar[i+1].x&&ar[i].y==ar[i+1].y) {
			sd=llabs(ar[i].x-ar[i+1].x)+llabs(ar[i].y-ar[i+1].y);
			flag=1;
		}
		else {
			flag=0;
			sd=llabs(ar[i].x-ar[i+1].x)-1+llabs(ar[i].y-ar[i+1].y);
		}
	}
	printf("%d\n",sum);
	
	return 0;
	
	return 0;
}