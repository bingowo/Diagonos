#include <stdio.h>

int main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        unsigned long long ans[75] = {};
        ans[0] = 0, ans[1] = 1, ans[2] = 1;
        int que; scanf("%d",&que);
        for (int j=3;j<=que;j++) ans[j] = ans[j-3]+ans[j-2]+ans[j-1];
        printf("%llu\n",ans[que]);
    }
    return 0;
}