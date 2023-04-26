#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
long long cal(int n)
{
    if(n==1 || n==0) return 1;
    if(n<0) return 0;
    return (2*cal(n-1)-cal(n-5));
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
