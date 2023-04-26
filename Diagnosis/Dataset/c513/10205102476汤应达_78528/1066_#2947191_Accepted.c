#include<stdio.h>

int main()
{
    int a[20][101],cas,n,p,m,t;scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d%d%d%d",&n,&p,&m,&t);
        for(int i=0;i<20;i++)
            for(int q=0;q<100;q++) a[i][q]=0;
        a[0][p]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j])
                {
                    if(j-1>0) a[i+1][j-1]+=a[i][j];
                    if(j+1<=n) a[i+1][j+1]+=a[i][j];
                }
            }
        }
        printf("%d\n",a[m][t]);
    }

    return 0;
}