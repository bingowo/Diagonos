#include <stdio.h>

long long int cal(int n,int m,int a,int b);

int
main()
{
    int questions;
    int a,b,k,n,m;
    long long int res;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        res = cal(n, m, a, b);
        printf("case %d:\n",i);
        printf("%lld\n",res);
    }
    
    return 0;
}

long long int cal(int n,int m,int a,int b)
{
    long long int res[1001][1001];
    
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i==0 && j==0)
            {
                res[i][j] = 1;
            }
            else if (i==0 && j!=0)
            {
                res[i][j] = b*res[i][j-1]%10007;
            }
            else if (j==0 && i!=0)
            {
                res[i][j] = a*res[i-1][j]%10007;
            }
            else
            {
                res[i][j] = (b*res[i][j-1] + a*res[i-1][j])%10007;
            }
        }
    }
    return res[n][m];
}