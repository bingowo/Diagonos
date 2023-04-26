#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long R;
    long long sum;
}P;

int cmp(const void* m, const void* n){
    P *a = (P*)m, *b = (P*)n;
    if(a->sum < b->sum) return 1;
    else return -1;
}

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    P* a =(P*)malloc(n*sizeof(P));
    for(int i=0; i<n; ++i) {
        long long H;
        scanf("%lld %lld",&a[i].R, &H);
        a[i].sum = a[i].R * H;
    }
    qsort(a, n, sizeof(P), cmp);
    long long max = 0;
    for(int k=0; k<n; ++k) {
        long long R = a[k].R;
        long long t = 2*a[k].sum + R*R;
        int cnt = 0;
        for(int i=0; cnt<m-1 && i<n; ++i) {
            if(a[i].R>R || i==k) continue;
            t += 2 * a[i].sum;
            ++cnt;
        }
        if(cnt==m-1 && t>max) max = t;
    }
    printf("%lld\n",max);
    free(a);
    return 0;
}

