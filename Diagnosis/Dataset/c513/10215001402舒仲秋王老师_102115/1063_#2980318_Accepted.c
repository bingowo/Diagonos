#include <stdio.h>
#include <stdlib.h>

long long int num(long long int a,long long int b)
{
    if(a==b) return 4*a;
    else if(a>b)
    {
        if(a%b==0) return 4*b*(a/b);
        else return 4*b+num(b,a-b);
    }
   else if(b>a)
    {
        if(b%a==0) return 4*a*(b/a);
        else return 4*a+num(a,b-a);
    }
}

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",num(a,b));
    return 0;
}

