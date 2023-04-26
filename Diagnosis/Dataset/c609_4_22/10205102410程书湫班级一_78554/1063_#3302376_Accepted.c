#include <stdio.h>
#include <stdlib.h>
unsigned long long ans[52];
unsigned long long solve(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    if(!ans[n])
    {
        ans[n]=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
    }
    return ans[n];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        unsigned long long a=solve(n);
        printf("case #%d:\n",cas);
        printf("%llu\n",a);
    }
    return 0;
}
