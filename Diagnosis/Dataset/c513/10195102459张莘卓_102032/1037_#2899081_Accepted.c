#include <stdio.h>
#include <stdlib.h>

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
    long long min = 0;
    for(int i=1; i<m; ++i) min += a[m-1] - a[m-1-i];
    long long t = min;
    for(int i=m; i<n; ++i) {
        t += (m-1) * (a[i]-a[i-1]) - (a[i-1]-a[i-m]);
        if(t < min) min = t;
    }
    printf("%lld\n",min);
    free(a);
    return 0;
}
