#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a,n,m,x,t;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int up[n],down[n],sum[n];
    up[0]=0;down[0]=0;sum[0]=0;
    up[1]=a;sum[1]=a;
    for(t=0;t<=m;t++)
    {
        up[2]=t;
        down[2]=t;
        for(int i=3;i<n;i++)
        {up[i]=up[i-1]+up[i-2];
        down[i]=up[i-1];
        sum[i]=sum[i-1]+up[i]-down[i];}
        if(sum[n-1]==m) {printf("%d",sum[x]);break;}
    }
    return 0;
    
    
}