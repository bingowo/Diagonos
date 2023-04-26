#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i += 2){
        sum = sum + a[i + 1] - a[i];
    }
    printf("%lld", sum);
    return 0;
}
