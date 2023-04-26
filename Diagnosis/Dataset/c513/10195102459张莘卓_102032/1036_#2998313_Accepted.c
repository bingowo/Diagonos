#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    long long x;
    long long y;
    unsigned long long s;
}P;

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

unsigned long long calculate(P* a, P* b) {
    unsigned long long s = 0;
    s += a->x>b->x ? a->x-b->x : b->x-a->x;
    s += a->y>b->y ? a->y-b->y : b->y-a->y;
    return s;
}

int digitCount(unsigned long long n) {
    int cnt = 0;
    while(n) {
        ++cnt;
        n /= 2;
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d",&n);
    P *a = (P*) malloc(n*sizeof(P)), zero = {0,0,0};
    for(int i=0; i<n; ++i) {
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].s = calculate(a+i, &zero);
    }
    qsort(a, n, sizeof(P), cmp);
    unsigned long long s = (unsigned long long) llabs(a[1].x-a[0].x) + (unsigned long long) llabs(a[1].y-a[0].y);
    if(!s && (a[1].x!=a[0].x || a[1].y!=a[0].y))
        printf("18446744073709551616\n");
    else printf("%llu\n",s);
    int ans = 0;
    for(int i=1; i<n; ++i) {
        if(a[i-1].x==a[i].x && a[i-1].y==a[i].y) continue;
        s = (unsigned long long) llabs(a[i].x-a[i-1].x) + (unsigned long long) llabs(a[i].y-a[i-1].y);
        if(s % 2 == 0) break;
        ans += digitCount(s);
    }
    printf("%d\n",ans);
    free(a);
    return 0;
}
