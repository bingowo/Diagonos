#include <stdio.h>
#include <string.h>
long long N2T(long long a)
{
    return(a<9)?a:N2T(a/10)*9+a%10;
}
long long f(long long a)
{
    long long d0 = a%10,x,n = 0;
    for(x = a-d0;x<=a;x++)
    {
        if(x%9==0) n++;
    }
    return n+N2T(a-a%10)/9;
}
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",N2T(b)-N2T(a)+1-f(b)+f(a));
    return 0;

}
