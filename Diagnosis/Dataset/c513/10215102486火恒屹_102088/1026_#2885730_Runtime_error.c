#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}

int main()
{
    int kazu;
    scanf("%d",&kazu);
    long long num[10003]={0};
    for(int i=0;i<kazu;i++)
        scanf("%lld",&num[i]);
    qsort(num,kazu,sizeof(long long),cmpfunc);
    long long sum=0;
    for(int i=0;i<kazu-1;i=i+2)
        sum=sum+num[i+1]-num[i];
    printf("%lld",sum);
    return 0;
}
