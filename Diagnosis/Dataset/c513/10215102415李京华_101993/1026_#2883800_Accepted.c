#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return *((int *)a) - *((int *)b);
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(a[0]), cmp);

    int ans = 0;
    for (i = 0; i < n; i += 2){
        ans += abs(a[i] - a[i+1]);
    }

    printf("%d", ans);
    return 0;
}