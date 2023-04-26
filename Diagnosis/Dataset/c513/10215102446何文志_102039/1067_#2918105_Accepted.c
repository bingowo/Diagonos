#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        long long n = 0;
        scanf("%lld",&n);
        long long memo[80];memset(memo,0,80*sizeof(long long));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        for(int j = 3;j<=n;j++)
        {
            memo[j] = memo[j-1]+memo[j-2]+memo[j-3];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",memo[n]);
    }
    return 0;
}
