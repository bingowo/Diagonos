#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef long long int lli;
typedef struct
{
    lli fenzi,fenmu;
}fraction;

int gcd(int a,int b)
{
    if(a>b) return (a%b==0?b:gcd(b,a%b));
    else return (b%a==0?a:gcd(a,b%a));
}

void ADD(fraction* result,fraction a)
{
    result->fenzi=result->fenzi*a.fenmu+result->fenmu*a.fenzi;
    result->fenmu=result->fenmu*a.fenmu;
}

int main()
{
    int n;
    scanf("%d",&n);
    fraction a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld/%lld",&a[i].fenzi,&a[i].fenmu);
    }

    fraction result={a[0].fenzi,a[0].fenmu};

    for(int i=1;i<n;i++)
    {
        ADD(&result,a[i]);
    }
    lli g=gcd(result.fenzi,result.fenmu);
    result.fenzi/=g;
    result.fenmu/=g;
    printf("%lld/%lld",result.fenzi,result.fenmu);
    return 0;
}