#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const int i1=*(int*)a,i2=*(int*)b;
	return i1-i2;
}

int main()
{
	int i,j=0,k;
	int len=0;
	long long pts[10000],result=0;
	scanf("%d",&len);
	for(i=0;i<len;i++)scanf("%lld",&pts[i]);
	qsort(pts,len,sizeof(long long),cmp);
	for(i=0;i<len;i+=2)result+=(pts[i+1]-pts[i]);
	printf("%d",result);
	return 0;
}