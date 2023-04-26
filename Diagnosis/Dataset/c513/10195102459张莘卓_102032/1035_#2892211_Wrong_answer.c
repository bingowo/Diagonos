#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int R;
    long long sum;
}P;

int cmp(const void* m, const void* n){
    P *a = (P*)m, *b = (P*)n;
    if(a->sum < b->sum) return 1;
    else if(a->sum > b->sum) return -1;
    else return b->R - a->R;
}

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    P a[1000];
    for(int i=0; i<n; ++i) {
        int H;
        scanf("%d %d",&a[i].R, &H);
        a[i].sum = a[i].R * H;
    }
    qsort(a, n, sizeof(P), cmp);
    unsigned long long s = 0, max = 0;
    for(int i=0; i<m; ++i) {
        if(a[i].R > max) max = a[i].R;
        s += a[i].sum;
    }
    printf("%llu\n",s*2+max*max);
    return 0;
}
