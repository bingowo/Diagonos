#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
long long cal(int n)
{
    if(n==1) return 1;
    if(n==0) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(n==4) return 8;
    if(n<0) return 0;
    return (cal(n-1)+cal(n-2)+cal(n-3)+cal(n-4));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long ans=cal(n);
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}
