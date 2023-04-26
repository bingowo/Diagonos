#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[21][1001];            //用前i个砝码称出j的重量  1or0
int main()
{
    int n, * w, i,j,maxsum=0;
    scanf("%d", &n);
    w = (int*)malloc(n*2 * sizeof(int));
    for (i = 0;i < n;i++)
    {
        scanf("%d", &w[i]);
        dp[i][w[i]] = 1;
        maxsum += w[i];
    }
    for (i = 1;i < n;i++)
    {
        for (j = 1;j <=maxsum;j++)
        {
            if (dp[i - 1][j] == 1)
            {
                dp[i][j] = 1;
                dp[i][j +w[i]] = 1;
                dp[i][abs(j - w[i])] = 1;                           //这里还不太懂，以后再说吧
            }
        }
    }
    int res = 0;
    for (j = 1;j <= maxsum;j++)
    {
        if (dp[n - 1][j] == 1)
            printf("1");
        else
            printf("0");
    }
    //printf("%d", res);
    
    free(w);
    return 0;
}

