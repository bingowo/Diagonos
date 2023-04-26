#include <stdio.h>
#include <stdlib.h>

void simplify(long long* pa, long long* pb) {
    long long a = *pa, b = *pb;
    while(b) {
        long long t=a%b; a = b; b = t;
    }
    *pa /= a;
    *pb /= a;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long a, b;
    scanf("%lld/%lld",&a, &b);
    simplify(&a, &b);
    for(int i=1; i<n; ++i) {
        long long c, d;
        scanf("%lld/%lld",&c, &d);
        simplify(&c, &d);
        a = a*d + b*c;
        b *= d;
        simplify(&a, &b);
    }
    printf("%lld/%lld\n",a, b);
    return 0;
}
