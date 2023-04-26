#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int llu;
llu rever(llu n)
{
    llu ret=0;
    while(n)
    {
        ret=ret*10+n%10;
        n/=10;
    }
    return ret;
}
int main()
{
    llu n,m;
    int cnt=0;
    scanf("%llu",&n);
    while((m=rever(n))!=n)
    {
        n=n+m;
        cnt++;
    }
    printf("%d %llu",cnt,n);
    return 0;
}
