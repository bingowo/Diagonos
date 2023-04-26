#include <stdio.h>
#include <string.h>
long long N[75];
long long change (long long n)
{
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    if (n==4) return 8;
    if (N[n]) return N[n];
    else
    {
        N[n]=change(n-1)+change(n-2)+change(n-3)+change(n-4);
        return N[n];
    }
}
int main ()
{
    int T;
    scanf ("%d",&T);
    for (int q=0;q<T;q++)
    {
        int n;
        scanf ("%d",&n);
        printf("case #%d:\n%lld\n",q,change(n));
    }
    return 0;
}
