#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n,k; scanf("%d %d",&n,&k);
        if (k>n/2) k = n-k;
        unsigned long long ans = 1;
        for (int j=1;j<=k;j++)
        {
            if (ans%j==0) ans = ans/j*(n-j+1);
            else ans = (n-j+1)/j*ans;
        }
        printf("case #%d:\n%llu\n",i,ans);
    }
    return 0;
}