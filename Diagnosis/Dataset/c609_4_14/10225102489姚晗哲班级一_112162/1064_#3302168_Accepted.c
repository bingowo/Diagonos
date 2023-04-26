#include <stdio.h>
#include <stdlib.h>
long long cal(long long a,long long b)
{
    if(a<b)
    {
        long long m=b;
        b=a;
        a=m;
    }
    if(b==0)
        return 0;
    long long v=(a/b)*4*b+cal(b,a%b);
    return v;
}
int main()
{
    long long a,b,res=0;
    scanf("%lld %lld\n",&a,&b);
    res=cal(a,b);
    printf("%lld",res);
    return 0;
}