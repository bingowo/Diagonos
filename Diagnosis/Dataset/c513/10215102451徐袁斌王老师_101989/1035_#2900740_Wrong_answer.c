#include<stdio.h>
#include<math.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
	int* A=(int*)a;
	int* B=(int*)b;
	if(*A<*B) return -1;
	else return 1;
}
int main()
{
	int n,m,a,b,sum[1000]={0},x=0,r=0;
	int *p=sum;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		sum[i]=2*a*b;
		if(a>r) r=a;
	}
	qsort(p,n,sizeof(int),cmp);
	for(int j=0;j<m;j++)
	{
		x=x+sum[j];
	}
	x=x+r*r;
	printf("%d",x);
	

	
	
	
	

	
	return 0;
	
	
 } 