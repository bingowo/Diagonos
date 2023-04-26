#include <stdio.h>
#include <stdlib.h>
int Compute(long long int n)
{
    int cnt = 0;
    while(n)
    {
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}
int cmp(const void* a, const void* b)
{
    long long xa = *(long long *)a,xb = *(long long *)b;
    if(Compute(xa)!= Compute(xb)) return Compute(xb) - Compute(xa);
    return xa - xb;
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        int N;scanf("%d",&N);
        long long *p;
        p = (long long *) malloc(N*sizeof(long long));
        for(int j = 0; j<N;j++) scanf("%lld",p+j);
        qsort(p,N,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j<N; j++)
            printf("%lld%c",*(p+j),j==N-1?'\n':' ');
    }
    return 0;
}