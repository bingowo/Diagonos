#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, h;
}cylinder;

int cmp(const void*_a, const void*_b){
    cylinder a = *(cylinder *)_a;
    cylinder b = *(cylinder *)_b;
    int sa =2 * a.h * a.r + a.r * a.r;
    int sb =2 * b.h * b.r + b.r * b.r;
    return sb - sa;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i;
    cylinder a[n];
    for (i = 0; i < n; i++)
        scanf("%d%d", &a[i].r, &a[i].h);

    qsort(a, n, sizeof(a[0]), cmp);
    
    //上底面积:r*r 侧面积:2*r*h
    long long ans = 0;
    ans = a[0].r*a[0].r;
    for (i = 0; i < m; i++)
        ans += 2 * a[i].r*a[i].h;
    
    printf("%lld", ans);

    return 0;
}