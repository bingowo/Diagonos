#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
long long f(int n)
{
    if(n==0 || n==1) return 1;
    if(n<0) return 0;
    return 2*f(n-1)-f(n-5);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",cas);
        printf("%lld\n",f(n));
    }
    return 0;
}
