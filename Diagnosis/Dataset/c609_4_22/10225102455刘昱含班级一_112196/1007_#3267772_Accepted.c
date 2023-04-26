#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
int cmp_up(const void*a, const void*b)
{
    long long p1 = *(long long*)a;
    long long p2 = *(long long*)b;
    return (p1 > p2);
}
int cmp_n1(const void*a, const void*b)
{
    long long p1 = *(long long*)a;
    long long p2 = *(long long*)b;
    int cnt1 = 0, cnt2 = 0;

    while (p1)
    {
        p1 = p1 & (p1 - 1);
        cnt1++;
    }
    while (p2)
    {
        p2 = p2 & (p2 - 1);
        cnt2++;
    }
    return (cnt2 - cnt1);
}
int main()
{
    int t, n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d", &n);
        long long a[n];
        for (int j = 0; j < n; j++){
            scanf("%lld",&a[j]);
        }
        qsort(a, n, sizeof(a[0]), cmp_up);
        qsort(a, n, sizeof(a[0]), cmp_n1);
        printf("case #%lld:\n",i);
        int k;
        for (k = 0; k < n-1; k++){
            printf("%lld ", a[k]);
        }
        printf("%lld\n", a[k]);
    }
}
