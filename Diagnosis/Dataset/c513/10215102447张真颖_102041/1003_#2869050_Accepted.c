#include <stdio.h>
#include <stdlib.h>

int count(long long value)
{
    int n=0;
    for(int i=0;i<64;i++)
    {
        if((value>>i)&1) n++;

    }
    return n;
}

int cmp(const void* a,const void* b)
{
    long long t,ia=*(long long*)a,ib=*(long long*)b;
    if(count(ib)>count(ia)) return 1;
    if(count(ib)<count(ia)) return -1;
    if(ia>ib) return 1;
    if(ia<ib) return -1;
    return 0;
}

int main()
{
   int T;
   scanf("%d\n",&T);
   for(int i=0;i<T;i++)
   {
       int N;
       long long arr[10000];
       scanf("%d\n",&N);
       for(int i=0;i<N;i++)
        scanf("%lld",arr+i);
       qsort(arr,N,sizeof(long long),cmp);
       printf("case #%d:\n",i);
       for(int i=0;i<N;i++)
        printf("%lld%c",arr[i],i!=N-1?' ':'\n');

   }
    return 0;
}