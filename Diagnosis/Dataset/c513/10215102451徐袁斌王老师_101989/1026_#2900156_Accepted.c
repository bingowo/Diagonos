#include<stdio.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	int *p1 = (int*)a;
	int *p2 = (int*)b;
	return *p1-*p2;
}
int main()
{
	int a[1000000],b,t,sum=0;
	int *p=a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&b);
		a[i]=b;
	}
	qsort(p,t,sizeof(int),cmp);
	for(int i=0;i<t;i=i+2)
	{
		sum=sum+(a[i+1]-a[i]);
	}
	printf("%d",sum);
	return 0;
	
	
 } 