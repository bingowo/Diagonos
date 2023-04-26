#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const *b)
{
    int s1=*(int *)a,s2=*(int *)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    long long int *A=(long long int *) malloc(x*sizeof(long long int));
    for(int i=0;i<x;i++)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,x,sizeof(long long int),cmp);
    long long int max=A[y-1];long long int sum=0;
    for(int i=0;i<y-1;i++)
    {
        sum+=max-A[i];
    }
    printf("%lld",sum);
}