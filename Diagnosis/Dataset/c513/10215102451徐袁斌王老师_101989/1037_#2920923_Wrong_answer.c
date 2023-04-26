#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	int * A=(int *)a;
	int * B=(int *)b;
	if(*A>*B) return 1;
	else return -1;
}
int main()
{
	int t,j,n,m,a[1000000],sum=0,ans=0;
	scanf("%d %d",&n,&m);
	for(t=0;t<n;t++)
	{
		scanf("%d",&a[t]);
	}
	int *p=a;
	qsort(p,n,sizeof(int),cmp);
	for(j=m;j<n;j++)
	{
		for(int k=j-m;k<j;k++)
		{
			sum=sum+(a[j+m-1]-a[k]);
		}
		if(sum>ans) ans=sum;
	}
	printf("%d",ans);
	

	
	return 0;
	
	
 } 