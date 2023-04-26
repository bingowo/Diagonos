#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long int lli;


lli reverse(lli n)
{
    lli m=0;
    while(n>0)
    {
        m=m*10+n%10;
        n/=10;
    }
    return m;
}
int main(void)
{
    lli n,m;
    scanf("%lld",&n);
    int cout=0;
    while (reverse(n)!=n)
    {
        n=reverse(n)+n;
        cout++;
    }
    printf("%d %lld", cout, n);
    return 0;
}


