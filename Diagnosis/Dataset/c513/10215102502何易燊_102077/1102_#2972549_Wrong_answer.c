#include <stdio.h>
#include <math.h>

int main()
{
    long long n; scanf("%lld",&n);
    if (n==0) {printf("(0,0)\n"); return 0;}
    int q = sqrt(n);
    int k;
    if (q%2==1) k = (q+1)/2;
    else k = q/2;
    long long d = n-(2*k-1)*(2*k-1);
    long long x,y;
    if (0<=d&&d<=2*k-1) {x = (k-1)-d; y = k;}
    else if (2*k-1<d&&d<=4*k-1) {x = -k; y = k-(d-2*k+1);}
    else if (4*k-1<d&&d<=6*k-1) {x = -k+(d-4*k+1); y = -k;}
    else {x = k-1; y = -k+(d-6*k-1);}
    printf("(%lld,%lld)\n",x,y);
    return 0;
}