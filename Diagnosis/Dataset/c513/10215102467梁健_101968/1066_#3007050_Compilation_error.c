#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int n,p,m,t;

int main()
{
    int cas;scanf("%d",&cas);
    for(int step=0;step<cas;step++){
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int f[21][n+1]={0};
        f[0][p]=1;
        int pos=1;
        for(int i=1;i<=m;i++){
            for(int j=p-pos;j<=p+pos;j++){
                if(j==n+1)break;
                if(j-1>=1&&j+1<=n)f[i][j]=f[i-1][j-1]+f[i-1][j+1];
                else if(j==1)f[i][j]=f[i-1][j+1];
                else if(j==n)f[i][j]=f[i-1][j-1];
            }
            pos*=2;
            if(p-pos<1)pos=p-1;
        }
        printf("%d\n",f[m][t]);
    }
    return 0;
}
