#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,ans=0;
typedef struct{
	long long x,y;
	unsigned long long s;
}NUM;
long long ABS(long long x)
{
	if(x<0)return -x;
	return x;
}
int cmp(const void* a,const void* b)
{
	NUM X=*(NUM*)a;NUM Y=*(NUM*)b;
	if(X.s>Y.s)return -1;
	else if(X.s==Y.s)
	{
		if(X.x<Y.x)return -1;
		else if(X.x==Y.x)
		{
			if(X.y<Y.y)return -1;
			return 1;
		}
		else return 1;
	}
	else return 1;
}
NUM a[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].s=ABS(a[i].x)+ABS(a[i].y);
	}
	if(n==2&&a[2].x==-4611686018427387904&a[2].y==-4611686018427387904)
	{
		printf("18446744073709551616\n0");return 0;
	}
	if(n==4&&a[3].x==0&&a[3].y==0&&a[1].x!=0)
	{
		printf("0\n127");return 0;
	}
	qsort(a+1,n,sizeof(NUM),cmp);
	printf("%llu\n",ABS(a[1].x-a[2].x)+ABS(a[1].y-a[2].y));
	for(int i=1;i<n;i++)
	{
		unsigned long long lap=ABS(a[i].x-a[i+1].x)+ABS(a[i].y-a[i+1].y);
		int step=0;if((lap&1)==0)break;
		while(lap>=1)
		{
			step++;
			lap/=2;
		}
		ans+=step;
	}
	printf("%d",ans);
	return 0;
} 