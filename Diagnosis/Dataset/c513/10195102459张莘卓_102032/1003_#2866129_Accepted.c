#include <stdio.h>
#include <stdlib.h>

int count(long long n) {
    int cnt = 0;
    long long t = 1;
    for(int i=0; i<64; ++i)
        if((t<<i) & n) ++cnt;
    return cnt;
}

int cmp(const void *pa, const void *pb) {
    long long a = *((long long*)pa);
    long long b = *((long long*)pb);
    int ret = count(b) - count(a);
    if(ret == 0) return a>b ? 1 : -1;
    else return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int N;
        scanf("%d",&N);
        long long *a = (long long*) malloc(N*sizeof(long long));
        for(int i=0; i<N; ++i)
            scanf("%lld",&a[i]);
        qsort(a, N, sizeof(long long),cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<N; ++i)
            printf("%lld%s",a[i],i+1<N?" ":"\n");
        free(a);
    }
    return 0;
}
