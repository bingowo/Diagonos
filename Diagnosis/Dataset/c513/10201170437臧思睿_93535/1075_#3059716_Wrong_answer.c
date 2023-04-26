#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,m,n;
    char c1='R',c2='D';
    char c[410];
    scanf("%d %d",&m,&n);
    int a[m][n],dp[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    dp[0][0]=a[0][0];
    for(i=1;i<m;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for(i=1;i<n;i++)
    {
        dp[0][i]=dp[0][i-1]+a[0][i];
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(dp[i-1][j]<=dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j]+a[i][j];
            }
            else
            {
                dp[i][j]=dp[i][j-1]+a[i][j];
            }
        }
    }
    /*for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",dp[m-1][n-1]);
    i=m-1;j=n-1;
    while(i>0&&j>0)
    {
        if(dp[i-1][j]<=dp[i][j-1])
        {
            sprintf(c,"%s%c",c,c2);
            i-=1;
        }
        else
        {
            sprintf(c,"%s%c",c,c1);
            j-=1;
        }
    }
    if(j)
    {
        while(j--)
        {
            printf("%c",'R');
        }
    }
    else
    {
        while(i--)
        {
            printf("%c",'D');
        }
    }
    for(i=0;i<strlen(c);i++)
    {
        printf("%c",c[strlen(c)-1-i]);
    }
    return 0;
}
