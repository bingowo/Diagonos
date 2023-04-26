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

        long long memo[51];memset(memo,0,51*sizeof(long long));
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;
        memo[4] = 8;

        for(int j = 5;j<=n;j++)
        {
            memo[j] = memo[j-1]+memo[j-2]+memo[j-3]+memo[j-4];
        }

        printf("case #%d:\n%lld\n",i,memo[n]);

    }
    return 0;
}
