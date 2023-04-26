#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 210
#define MOD 1000000007

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char s[101];
        scanf("%s",s);
        int len = strlen(s);
        int j,k,m;
        int ar[101][210] = {1};
        for(j = 0;j < len;j++)
        {
            int sum = 0;
            for(k = j;k < len;k++)
            {
                sum = (sum*10 + s[j] - '0') % M;
                for(m = 0;m < 210;m++)
                {
                    
                    ar[k + 1][(m + sum) % M] = (ar[k + 1][(m + sum) % M] + ar[j][m]) % MOD;
                    if(i) ar[k + 1][(m + M - sum) % M] = (ar[k + 1][(m + M - sum) % M] + ar[j][m]) % MOD; 
                }
                
            }
        }
        int ans = 0;
        for(j = 1;j < len;j++)
            for(k = 0;k < 210;k++)
            {
                ans += ar[j][k]; 
            }
        printf("%d\n",ans);
    }
    return 0;
}