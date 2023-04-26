#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    long long n,m;
    scanf("%lld%lld",&m,&n);
    long long a,b;
    a=n>m?n:m;
    b=n>m?m:n;
    long long cnt=a/b;
    printf("%lld",4*b*cnt);
    return 0;
}
