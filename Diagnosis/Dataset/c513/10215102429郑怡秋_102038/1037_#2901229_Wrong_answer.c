#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int*p1=(int*)a;int*p2=(int*)b;
	if(*p1>*p2) return 1;
	else return -1; 
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *p=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	qsort(p,n,sizeof(int),cmp);
	unsigned long long res=0,ans=0;
	for(int i=0;i<m;i++)
	{
		res+=p[m-1]-p[i];
	}
	for(int i=m;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans+=p[i]-p[j];
		}	
		ans-=p[i]-p[i-m];
		if(res>ans) res=ans;
	}
	printf("%llu",res);
	return 0;
}