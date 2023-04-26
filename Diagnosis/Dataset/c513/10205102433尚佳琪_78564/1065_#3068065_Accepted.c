#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x,t,i;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int sum[21]={0},up[21]={0},down[21]={0};
    sum[1]=a;up[1]=a;down[1]=0;
    for(t=0;t<=m;t++)
    { sum[2]=a;up[2]=t;down[2]=t;
        for( i=3;i<n;i++)
        {
            up[i]=up[i-1]+up[i-2];
            down[i]=up[i-1];
            sum[i]=sum[i-1]+up[i]-down[i];
        }
        if(sum[i-1]==m){break;}
    }
    printf("%d",sum[x]);
}