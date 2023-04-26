#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int lli;
const double ep= 1e-8;

double get(lli x)
{
    double ret = 0;
    while (x!=0) {
        ret = x%10;
        x/=10;
    }
    if(ret<0){
        ret = -ret+0.5;
    }
    return ret;
}

int cmp(const void *a, const void *b)
{
    lli na = *(lli *)a;
    lli nb = *(lli *)b;
    if(fabs(get(na)-get(nb))>=ep){
        return get(na)<get(nb)?1:-1;
    }
    else{
        return na>nb?1:-1;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n;
        scanf("%d",&n);
        lli input[n];
        for (int j=0; j<n; j++) {
            scanf("%lld",&input[j]);
        }
        qsort(input, n, sizeof(lli), cmp);
        printf("case #%d:\n",i);
        for (int j=0; j<n; j++) {
            printf("%lld%c",input[j],j==n?'\n':' ');
        }
    }
    return 0;
}
