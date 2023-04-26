#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long f1,f2;
}F;

int gcd(int a,int b)
{
    if(a > b)
        return (a % b == 0 ? b : gcd(b,a%b));
    else
        return (b % a == 0 ? a : gcd(a,b%a));
}

void ADD(F* result,F a)
{
    result->f1 = result->f1 * a.f2 + result->f2 * a.f1;
    result->f2 = result->f2 * a.f2;
}

int main()
{
    int n;
    scanf("%d",&n);
    F a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%lld/%lld",&a[i].f1,&a[i].f2);
    }

    F result={a[0].f1,a[0].f2};

    for(int i = 1; i < n; i++)
    {
        ADD(&result,a[i]);
    }
    long long g = gcd(result.f1,result.f2);
    result.f1 /= g;
    result.f2 /= g;
    printf("%lld/%lld",result.f1,result.f2);
    return 0;
}
