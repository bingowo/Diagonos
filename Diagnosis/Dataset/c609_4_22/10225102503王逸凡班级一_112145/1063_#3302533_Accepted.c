#include <stdio.h>
#include <stdlib.h>

long long ans[51]={0};

long long int solve(int n)
{
    if (n<0) return 0;
    if (n==0) return 1;
    if (ans[n] == 0)
    {
        ans[n] = solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
    }
    return ans[n];
}
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for (int i = 0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,solve(n));
    }
    return 0;
}
