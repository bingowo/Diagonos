#include <stdio.h>
#include <stdlib.h>

int cun[32][32];
int mid[32];
int way(int n,int m)
{
    if(n<m) return 0;
    else if(n==m) return 1;
    else
    {
        if(mid[n-1-m]==-1) mid[n-1-m]=pow(2,n-1-m);
        if((cun[n-1][m]!=-1)&&(cun[n-1-m][m]!=-1)) cun[n][n]=2*cun[n-1][m]-cun[n-1-m][m]+mid[n-1-m];
        else cun[n][m]=2*way(n-1,m)-way(n-1-m,m)+mid[n-1-m];
        return cun[n][m];
    }
}

int main()
{
    while(1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if((m==-1)&&(n==-1)) break;
        int re,i,j;
        for(i=0;i<32;i++)
        {
            for(j=0;j<32;j++)
            {
                cun[i][j]=-1;
            }
        }
        memset(mid,-1,sizeof(int)*32);
        re=way(n,m);
        printf("%d\n",re);

    }
    return 0;
}
