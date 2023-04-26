#include <stdio.h>

int main()
{
    int cas,n,p,m,t,i,j,k;
    int x[100],y[100];
    scanf("%d",&cas);
    for(i=0;i<cas;i++){
        scanf("%d%d%d%d",&n,&p,&m,&t);
        for(j=0;j<n;j++)
            x[j]=0;
        x[p-1]=1;
        for(j=0;j<m;j++){
            y[0]=x[1];
            y[n-1]=x[n-2];
            for(k=1;k<n-1;k++)
                y[k]=x[k-1]+x[k+1];
            for(k=0;k<n;k++)
                x[k]=y[k];
        }
        printf("%d\n",x[t-1]);
    }
    return 0;
}
