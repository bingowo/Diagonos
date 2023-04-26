#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a,n,m,x;
int up[2][105],down[2][105],sum[2][105];

int main()
{
    scanf("%d%d%d%d",&a,&n,&m,&x);
    up[0][1]=a;
    up[1][1]=0;
    down[0][1]=0;
    down[1][1]=0;
    up[0][2]=0;
    up[1][2]=1;
    down[0][2]=0;
    down[1][2]=1;
    sum[0][1]=a;
    sum[1][1]=0;
    sum[0][2]=a;
    sum[1][2]=0;
    int t=0;
    for(int i=3;i<=n-1;i++)
    {
        up[0][i]=up[0][i-1]+up[0][i-2];
        up[1][i]=up[1][i-1]+up[1][i-2];
        down[0][i]=up[0][i-1];
        down[1][i]=up[1][i-1];
        sum[0][i]=sum[0][i-1]+up[0][i]-down[0][i];
        sum[1][i]=sum[1][i-1]+up[1][i]-down[1][i];
        //printf("!!%d %d %d %d\n",sum[0][i],sum[1][i],up[1][i],down[1][i]);
    }
    
    if(sum[1][n-1]!=0)
        t=(m-sum[0][n-1])/sum[1][n-1];
    printf("%d\n",sum[0][x]+sum[1][x]*t);
    return 0;
}