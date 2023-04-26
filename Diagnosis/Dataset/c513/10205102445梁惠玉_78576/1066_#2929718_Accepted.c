#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n,p,m,t;
    scanf("%d %d %d %d",&n,&p,&m,&t);
    int f[20][101]={0};
    f[0][p]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=1)
            {
                f[i][j]+=f[i-1][j-1];
            }
            if(j!=n)
            {
                f[i][j]+=f[i-1][j+1];
            }
        }
    }
    printf("%d\n",f[m][t]);
}

int main()
{
    int cas;
    scanf("%d",&cas);
    for(int x=0;x<cas;x++)
    {
        solve();
    }
    return 0;
}