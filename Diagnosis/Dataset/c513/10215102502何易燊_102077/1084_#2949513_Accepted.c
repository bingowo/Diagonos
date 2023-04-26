#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n; scanf("%d",&n);
        long long ans = (n==0)?1:1<<n;
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}