#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long x;
    long long y;
    unsigned long long s;
} P;

int cmp(const void* m, const void* n) {
    P *a=(P*)m, *b=(P*)n;
    if(a->s < b->s)  return 1;
    else if(a->s == b->s){
        if(a->x > b->x) return 1;
        else if(a->x == b->x)
            if(a->y > b->y) return 1;
    }
    return -1;
}
int bit1Count(unsigned long long n) {
    int i = 0;
    while(n) {
        n = n >> 1;
        ++i;
    }
    return i;
}

int main()
{
    int n;
    scanf("%d",&n);
    P a[100];
    for(int i=0; i<n; ++i){
        scanf("%lld %lld",&a[i].x, &a[i].y);
        a[i].s += a[i].x >= 0 ? a[i].x : -a[i].x;
        a[i].s += a[i].y >= 0 ? a[i].y : -a[i].y;
    }
    qsort(a, n, sizeof(P), cmp);
    int cnt = 0;
    for(int i=0; i<n-1; ++i) {
        unsigned long long l = 0;
        if(a[i].x>a[i+1].x)
            l += a[i].x - a[i+1].x;
        else l += a[i+1].x - a[i].x;
        if(a[i].y>a[i+1].y)
            l += a[i].y - a[i+1].y;
        else l += a[i+1].y - a[i].y;
        if(i == 0) printf("%llu\n",l);
        if(l % 2 == 0) break;
        cnt += bit1Count(l);
    }
    printf("%d\n",cnt);
    return 0;
}
