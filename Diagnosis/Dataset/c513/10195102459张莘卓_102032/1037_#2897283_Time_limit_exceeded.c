#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int cmp(const void *m, const void *n) {
    long long a=*(long long*)m, b=*(long long*)n;
    if(a > b) return 1;
    else return -1;
}

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    long long *a = (long long*)malloc(n*sizeof(long long));
    for(int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    qsort(a, n, sizeof(long long), cmp);
    long long min = LLONG_MAX;
    for(int i=m-1; i<n; ++i) {
        long long t = 0;
        for(int k=1; k<m; k++) t += a[i] - a[i-k];
        if(t < min) min = t;
    }
    printf("%lld\n",min);
    return 0;
}
