#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 210
#define MOD 100000007

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char s[101];
        scanf("%s",s);
        int len = strlen(s);
        int ar[101][210] = {{0}};
        int j,k,m;
        for(j = 0;j < len;j++)
        {
            int sum = 0;
            for(k = j;k < len;k++)
            {
                sum = ((sum*10)%M + (s[j] - '0')%M) % M;
                for(m = 0;m < 209;m++)
                {
                    ar[k + 1][(m + sum) % M] = (ar[k + 1][(m + sum) % M] % MOD + ar[j][m] % MOD) % MOD;
                    ar[k + 1][(m + M - sum) % M] = (ar[k + 1][(m + M - sum) % M] % MOD + ar[j][m] % MOD) % MOD; 
                }
            }
        }
        int ans = 0;
        for(k = 0;k < 210;k++)
        {
            if(k % 2 == 0 || k % 3 == 0 || k % 5 == 0 || k % 7 == 0)
                ans += ar[len - 1][k]; 
        }
        printf("%d\n",ans);
    }
    return 0;
}