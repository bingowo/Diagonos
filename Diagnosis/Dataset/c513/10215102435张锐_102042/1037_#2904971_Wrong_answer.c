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
    for(long long int i=0;i<x;i++)
    {
        scanf("%lld",&A[i]);
    }
    qsort(A,x,sizeof(long long int),cmp);
    long long int sum=0,all=0;
    for(int i=0;i<y-1;i++)
    {
        sum+=A[i];
    }
    all=A[y-1]*(y-1)-sum;
    for(long long int i=1;(i+y-1)<x;i++)
    {
        long long int max=A[i+y-1];
        sum=sum-A[i-1]+A[i+y-2];
        long long int temp=max*(y-1)-sum;
        if(temp<all) all=temp;
    }
    printf("%lld",all);
}