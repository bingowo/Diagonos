#include <stdio.h>
#include <math.h>
int dp(int n,int p,int m,int t)
{
    int res = 0,i,a[100][100],k[100]={1},j;
    a[0][0] = p;
    for(i = 1;i<=m;i++)
    {
        for(j = 0;j<k[i-1];j++)
        {
            if(a[i-1][j]==1) a[i][k[i]++] = 2;
            else if(a[i-1][j]==n) a[i][k[i]++] = n-1;
            else
            {
                a[i][k[i]++] = a[i-1][j]-1;
                a[i][k[i]++] = a[i-1][j]+1;
            }
        }
    }
    for(j = 0;j<k[i-1];j++)
    {
        if(a[m][j]==t) res++;
    }
    return res;
}
int main()
{
    int cas,i;
    scanf("%d",&cas);
    for(i = 0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",dp(n,p,m,t));

    }
    return 0;
}
