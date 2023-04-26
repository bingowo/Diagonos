#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hignNum(long long n) {
    while(n / 10) n /= 10;
    return n < 0 ? -n : n;
}

int cmp(const void* m, const void* n) {
    long long a = *((long long*)m), b = *((long long*)n);
    int t = hignNum(b) - hignNum(a);
    if(t) return t;
    else if(a > b)  return 1;
    else  return -1;
}
 
int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int N; scanf("%d",&N);
        long long a[10000];
        for(int i=0; i<N; ++i) scanf("%lld",&a[i]);
        qsort(a, N, sizeof(long long), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<N; ++i)
            printf("%lld%s",a[i],i<N-1?" ":"\n");
    }
    return 0;
}
