#include <stdio.h>
#include <stdlib.h>

#define MAX 10020

int D[MAX][MAX];
int dp[MAX][MAX];
char mp[MAX];

int minn(int a,int b)
{
    return (a>b)?b:a;
}

int main()
{
    int M,N,k=0;
    scanf("%d %d",&M,&N);
    for (int i=0;i<M;i++)
        for (int j=0;j<N;j++)
            scanf("%d",&D[i][j]);
    dp[0][0]=D[0][0];
    for (int i=1;i<M;i++)
        dp[i][0]=dp[i-1][0]+D[i][0];
    for (int j=1;j<N;j++)
        dp[0][j]=dp[0][j-1]+D[0][j];
    for (int i=1;i<M;i++)
        for (int j=1;j<N;j++)
            dp[i][j]=minn(dp[i-1][j],dp[i][j-1])+D[i][j];
    int i=M-1,j=N-1;
    while (i>=0 && j>=0)
    {
        if (i==0 && j==0)
            break;
        else if (i==0)
        {
            mp[k++]='R';
            j--;
        }
        else if (j==0)
        {
            mp[k++]='D';
            i--;
        }
        else
        {
            if (dp[i-1][j]<dp[i][j-1])
            {
                mp[k++]='D';
                i--;
            }
            else
            {
                mp[k++]='R';
                j--;
            }
        }
    }
    printf("%d\n",dp[M-1][N-1]);
    for (int i=k-1;i>=0;i--)
        printf("%c",mp[i]);

    return 0;
}
