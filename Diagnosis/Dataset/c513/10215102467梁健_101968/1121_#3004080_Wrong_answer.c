#include<stdio.h>
#include<math.h>

int f[12][1010];
int w[12];

int main()
{
    int n,sum=0;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]),sum+=w[i];
    f[0][sum]=1;
    for(int i=1;i<=n;i++){
        for(int j=-sum;j<=sum;j++){
            f[i][j+sum]=f[i-1][j+sum];
            if(j-w[i]>=-sum)f[i][j+sum]|=f[i-1][j-w[i]+sum];
            if(j+w[i]<=sum)f[i][j+sum]|=f[i-1][j+w[i]+sum];
        }
    }
    for(int i=1;i<=sum;i++)printf("%d",f[n][i]);
    return 0;
}
