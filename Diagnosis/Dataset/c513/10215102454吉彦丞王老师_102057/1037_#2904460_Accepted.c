#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long int *A=(long long int *)a;
    long long int *B=(long long int *)b;
    if(*A>*B) return -1;
    else return 1;
}
int main()
{
    int n=0,m=0;
    long long int max=0,thismax=0;
    scanf("%d %d",&n,&m);
    long long int *L=(long long int*)malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++) scanf("%lld",&L[i]);
    qsort(L,n,sizeof(long long int),cmp);
    for(int t=0;t<m;t++) 
	{
		thismax+=L[0]-L[t];
	}
    max=thismax;
    for(int k=1;k<n-m+1;k++)
    {
    	thismax=thismax+L[k]-L[k+m-1]+(m-1)*(L[k]-L[k-1]);
		if(max > thismax) max=thismax;
    }
    printf("%lld",max);
    free(L);
    return 0;
}