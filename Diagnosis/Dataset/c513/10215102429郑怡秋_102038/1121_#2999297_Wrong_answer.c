#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int* p1=(int*)a;
	int* p2=(int*)b;
	if(*p1>*p2) return 1;
	else return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int w[20],s[2000]={0};
	w[0]=0;
	int sum=0;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),sum+=w[i],s[w[i]]=1;
	qsort(w,n,sizeof(w[0]),cmp);
	int tump=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			tump+=w[j];
			s[sum-tump*2]=1;
		}
	}
	for(int k=1;k<=sum;k++) printf("%d",s[k]);
	
	return 0;
}