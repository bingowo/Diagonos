#include <stdio.h>
#define M 1000
#define N 10007


int f(int n,int m,int a, int b)
{
    static int dp[M][M]={1};
    int i,j;
    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
            if (i+j)
                if (i==0)
                    dp[i][j] = b*dp[i][j-1]%N;
                else if (j==0)
                    dp[i][j] = a*dp[i-1][j]%N;
                else
                    dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
    return dp[n][m];
}

int main(){
    int num,now=0,a,b,k,n,m;
    scanf("%d",&num);
    while(now<num){
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #");
        printf("%d:\n",now);
        printf("%d\n",f(n,m,a,b));
        now++;
    }
    return 0;
}