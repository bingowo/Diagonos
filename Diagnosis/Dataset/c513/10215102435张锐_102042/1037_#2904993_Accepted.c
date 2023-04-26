#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const *b)
{
    unsigned long long s1=*(unsigned long long *)a,s2=*(unsigned long long *)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    unsigned long long *A=(unsigned long long*) malloc(x*sizeof(unsigned long long));
    for(long long int i=0;i<x;i++)
    {
        scanf("%lld",&A[i]);
    }
    qsort(A,x,sizeof(unsigned long long),cmp);
    unsigned long long sum=0,all=0;
    for(int i=0;i<y-1;i++)
    {
        sum+=A[i];
    }
    all=A[y-1]*(y-1)-sum;
    for(long long int i=1;(i+y-1)<x;i++)
    {
        unsigned long long max=A[i+y-1];
        sum=sum-A[i-1]+A[i+y-2];
        unsigned long long temp=max*(y-1)-sum;
        if(temp<all) all=temp;
    }
    printf("%llu",all);
}