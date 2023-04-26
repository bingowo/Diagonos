#include<stdio.h>

int f[12][1010],w[12];
int main()
{
    for(int i=0;i<12;i++)
        for(int j=0;j<1010;j++)
            f[i][j]=0;
    int n;scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            f[i][j]=f[i-1][j];//不放
            f[i][j]=f[i-1][j-w[i]]||f[i][j];//第i个砝码放右盘
            if(j+w[i]<=sum)f[i][j]=f[i-1][j+w[i]]||f[i][j];//第i个砝码放左盘
        }
    }
    for(int i=1;i<=sum;i++){
        if(f[n][i])printf("1");
        else printf("0");
    }
    return 0;
}
