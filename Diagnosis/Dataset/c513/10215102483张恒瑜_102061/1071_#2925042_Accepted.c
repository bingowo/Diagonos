#include<stdio.h>

int cal(int a,int b,int n,int m)
{
    static long long res[1000][1000]={1};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i+j)
            {
                if(i==0)
                    res[i][j]=(b%10007)*(res[i][j-1]%10007)%10007;
                else if(j==0)
                    res[i][j]=(a%10007)*(res[i-1][j]%10007)%10007;
                else
                    res[i][j]=(a*res[i-1][j]%10007+b*res[i][j-1]%10007)%10007;
            }
        }
    }
    return res[n][m];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int a,b,k,m,n;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #%d:\n%d\n",t,cal(a,b,n,m));
    }
}