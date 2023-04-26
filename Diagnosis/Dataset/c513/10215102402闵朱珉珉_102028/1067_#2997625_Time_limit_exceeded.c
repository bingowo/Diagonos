#include <stdio.h>
#include <string.h>
long long change (long long n)
{
    if (n==0) return 0;
    else if (n==1||n==2) return 1;
    else return change(n-1)+change(n-2)+change(n-3);
}
int main ()
{
    int T;
    scanf ("%d",&T);
    for (int q=0;q<T;q++)
    {
        long long n;
        scanf ("%lld",&n);
        printf("case #%d:\n%lld\n",q,change(n));
    }
    return 0;
}
