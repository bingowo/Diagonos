#include<stdio.h>
int f(int a,int b,int n,int m)
{
    static int map[1050][1050]={1};
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i+j!=0)
            {
                if(i!=0)
                {
                    if(j==0)  map[i][j]=map[i-1][j]*(a%10007)%10007;
                    else  map[i][j]=(map[i-1][j]*(a%10007)%10007+map[i][j-1]*(b%10007)%10007)%10007;
                }
                else
                {
                    map[i][j]=map[i][j-1]*(b%10007)%10007;
                }
            }
        }
    }
    return map[n][m];
}
int main()
{
    int T,i,j,a,b,k,n,m;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n%d\n",i,f(a,b,n,m));
    }
    return 0;
}