#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
   return *(long long *)a - *(long long *)b;
}

int main()
{
    int n, i;
    long long *N;
    unsigned long long cot = 0;
    scanf("%d", &n);
    N = (long long *)malloc(n * sizeof(long long));
    for (i = 0;i < n;i++){
        scanf("%lld", &N[i]);
    }
    qsort(N, n, sizeof(long long), cmp);
    for (i = 0;i < n - 1;i += 2){
        cot += abs(N[i] - N[i + 1]);
    }
    printf("%llu", cot);
    return 0;
}