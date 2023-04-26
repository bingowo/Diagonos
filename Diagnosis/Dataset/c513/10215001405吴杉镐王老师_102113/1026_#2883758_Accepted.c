#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a,const void* b) 
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(m<=n) return -1;
    else return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int res[1000001];
	int i=0;
	for(;scanf("%d",&res[i])!=EOF;i++);
	qsort(res,i,sizeof(res[0]),cmp);
	int sum=0;
	for(int k=0;k<i;k=k+2)
	{
		sum=sum+abs(res[k]-res[k+1]);
	}
	printf("%d",sum);
	return 0;
}