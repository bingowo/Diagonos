#include <stdlib.h>
#include <math.h>

typedef long long int lli;

lli ffa(lli x)
{
    return x<0?-x:x;
}

int cmp(const void *a,const void *b)
{
    lli m,n;
    m=*(lli *)a;
    n=*(lli *)b;
    return m>n?1:-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    lli point[n];
    lli distance=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&point[i]);
    }
    qsort(point,n,sizeof(lli),cmp);
    for (int i = 0; i < n; i+=2) {
        distance+= llabs(point[i]-point[i+1]);
    }
    printf("%lld",distance);
    return 0;
}
