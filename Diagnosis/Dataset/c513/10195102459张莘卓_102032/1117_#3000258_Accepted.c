#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

long long max(long long a, long long b){
    return a > b ? a : b;
}

int main()
{
    int n;
    long long a, b, px, py, min;
    px = py = min = LLONG_MAX;
    scanf("%lld %lld %d",&a, &b, &n);
    for(int i=0; i<n; ++i) {
        long long x, y, s;
        scanf("%lld %lld",&x, &y);
        s = max(llabs(x-a), llabs(y-b));
        if(s<min || (s==min && x<px) || (s==min && x==px && y<py)) {
            min =s; px = x; py = y;
        }
    }
    printf("%lld\n%lld %lld\n",min, px, py);
    return 0;
}
