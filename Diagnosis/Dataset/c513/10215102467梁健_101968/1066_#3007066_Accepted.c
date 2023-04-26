#include<stdio.h>
int n,p,m,t;
int main()
{
    int cas;scanf("%d",&cas);
    for(int step=0;step<cas;step++){
        scanf("%d %d %d %d",&n,&p,&m,&t);//n楼，p
        int f[21][101]={0};
        f[0][p]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j>1&&j<n)f[i][j]=f[i-1][j-1]+f[i-1][j+1];
                else if(j==1)f[i][j]=f[i-1][j+1];
                else if(j==n)f[i][j]=f[i-1][j-1];
            }
        }
        printf("%d\n",f[m][t]);
    }
    return 0;
}
