#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n;  scanf("%d",&n);
        int a[1000], b[1000];
        for(int i=0; i<n; ++i) scanf("%d",&a[i]);
        for(int i=0; i<n; ++i) scanf("%d",&b[i]);
        qsort(a, n, sizeof(int), cmp);
        qsort(b, n, sizeof(int), cmp);
        long long sum = 0;
        for(int i=0; i<n; ++i)
            sum += a[i] * b[n-1-i];
        printf("case #%d:\n%lld\n",j,sum);
    }
    return 0;
}
