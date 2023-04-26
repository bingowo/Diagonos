#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int u[21];
int v[21];
int main()
{
    int a,n,m,x,i,t=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    u[0]=0;u[1]=1;u[2]=0;
    v[0]=0;v[1]=0;v[2]=1;
    for(i=3;i<n;i++)
    {
        v[i]=v[i-1]+v[i-2];
        u[i]=v[i-1];
        //printf("(u[i]=%d,v[i]=%d)",u[i],v[i]);
    }//预处理系数
    //printf("\n");
    int up[21]={0},down[21]={0},sum[21]={0};
    up[1]=a,down[1]=0;
    sum[0]=0,sum[1]=a,sum[2]=a,t=m/2;
    int sign=1;
    while(sign==1&&t<=m&&t>=0)
    {
        up[2]=t,down[2]=t;
        for(i=3;i<n;i++)
        {
            up[i]=u[i]*a+v[i]*t;
            down[i]=up[i-1];
            sum[i]=sum[i-1]+up[i]-down[i];
            //printf("sum%d=%d\n",i,sum[i]);
        }
        if(sum[n-1]==m){printf("%d\n",sum[x]);sign=0;}
        else if(sum[n-1]<m)t++;
        else t--;
    }
    return 0;
}
