#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int yoshi(long long a)
{
    if(a%9==0) return 0;
    while(a>0)
    {
        if(a%10==9) return 0;
        a=a/10;
    }
    return 1;
}
int main()
{
    long long a;
    scanf("%lld",&a);
    a++;
    while(yoshi(a)!=1)
        a++;
    printf("%lld",a);
    
}
