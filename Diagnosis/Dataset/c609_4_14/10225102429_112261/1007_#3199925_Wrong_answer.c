#include <stdio.h>
#include <stdlib.h>
int Compute(long long int n)
{
    long long int k = 1;
    for(int i = 0; i<64; i++) k*=2;
    long long com = k-n;
    int cnt = 0;
    while(com)
    {
        com = com&(com-1);
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
        for(int i = 0; i<N;i++) scanf("%lld",p+i);
        qsort(p,N,sizeof(long long),cmp);
        for(int i = 0; i<N; i++){
            printf("%lld%c",*(p+i),i==N-1?'\n':' ');
        }
    }
    return 0;
}