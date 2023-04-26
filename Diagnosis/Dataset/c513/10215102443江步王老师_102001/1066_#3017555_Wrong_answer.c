#include<stdio.h>
#include<malloc.h>


void f(int** dp,int n,int m,int p);
int main()
{
    int w;
    scanf("%d",&w);
    for (int i=0;i<w;++i)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        p--;t--;

        //创建二维数组dp,存放到达每一点的行走方案总数
        int** dp = (int** )malloc(sizeof(int*)*(m+1));
        for (int j=0;j<m+1;++j)
        {
            dp[j]=(int* )malloc(sizeof(int)*n);
        }

        for (int j=0;j<m+1;++j)
        {
            for(int k=0;k<n;++k)
            {
                dp[j][k]=0;
            }
        }
        f(dp,n,m,p);

        printf("%d\n",dp[m][t]);
        for (int j=0;j<m+1;++j)
        {
            free(dp[j]);
        }
        free(dp);
    }   
    return 0;
}

void f(int** dp,int n,int m,int p)
{
    int i=0,j;
    
    if (p==0)
    {
        dp[1][p+1]=1;
    }
    else if(p==n-1)
    {
        dp[1][p-1]=1;
    }
    else
    {
        dp[1][p-1]=1;
        dp[1][p+1]=1;
    }
    i++;
    while(i<m)
    {
        for (j=0;j<n;++j)
        {
            if (dp[i][j]!=0)
            {
                if (j==0)
                {
                    dp[i+1][j+1]++;
                }
                else if (j==n-1)
                {
                    dp[i+1][j-1]++;
                }
                else
                {
                    dp[i+1][j-1]++;
                    dp[i+1][j+1]++;
                }
            }
        }
        ++i;
    }
    return;
}