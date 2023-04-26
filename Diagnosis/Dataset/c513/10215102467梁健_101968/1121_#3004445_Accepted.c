#include<stdio.h>
#include<math.h>
int f[12][114514],w[12];
int main()
{
    int n,sum=0;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]),sum+=w[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=sum;j++)
            f[i][j]=f[i-1][j]||f[i-1][abs(j-w[i])]||f[i-1][j+w[i]];
    for(int i=1;i<=sum;i++)printf("%d",f[n][i]);
    return 0;
}
