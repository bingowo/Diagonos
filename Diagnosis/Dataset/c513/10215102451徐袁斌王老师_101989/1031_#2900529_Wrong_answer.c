#include<stdio.h>
#include<math.h>
#include<string.h>

int cmp1(const void *a,const void *b)
{
	int* A=(int*)a;
	int* B=(int*)b;
	if((*A>0&&*B>0)||(*A<0&&*B<0)) return(*B-*A);
	else
	{
		if(*A>0&&*B<0) return -1;
		else return 1;
	}
	
}
int cmp2(const void *a,const void *b)
{
	int* A=(int*)a;
	int* B=(int*)b;
	if((*A>=0&&*B>=0)||(*A<=0&&*B<=0)) return(*A-*B);
	else
	{
		if(*A>=0&&*B<=0) return 1;
		else return -1;
	}
	
}
int main()
{
	int t,n,a[1000],b[1000],sum[10]={0};
	int *p1=a,*p2=b;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=0;j<n;j++)
		{
			scanf("%d",&b[j]);
		}
		qsort(p1,n,sizeof(int),cmp1);
		qsort(p2,n,sizeof(int),cmp2);
		for(int j=0;j<n;j++)
		{
			sum[i]=sum[i]+a[j]*b[j];
		}
	}
	
	
	
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%d\n",i,sum[i]);
	}
	
	
	
	

	
	return 0;
	
	
 } 