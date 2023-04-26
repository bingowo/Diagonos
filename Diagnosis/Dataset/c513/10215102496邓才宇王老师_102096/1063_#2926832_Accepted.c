#include <stdio.h>
#include <stdlib.h>
long long int ans(long long int a,long long int b)
{
    if(a%b==0)
    {
        return 4*b*(a/b);
    }
    long long int num=0;
    if(a==b) return 4*a;
    else
    {
        while(a>b)
        {
            num=num+4*b;
            a=a-b;
        }
        if(a==b) return num+4*a;
        else return num+ans(b,a);
    }
}
int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",ans(a,b));
}
