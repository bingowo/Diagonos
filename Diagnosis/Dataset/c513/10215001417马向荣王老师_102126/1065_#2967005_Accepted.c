#include<stdio.h>
int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int up[21];
    int down[21];
    int sum[21];
    up[1]=a;
    down[1]=0;
    sum[1]=a;
    sum[2]=a;
    for(int t=0;t<=m;t++)
    {
        up[2]=t;
        down[2]=t;
        for(int i=3;i<n;i++)
        {
            up[i]=up[i-1]+up[i-2];
            down[i]=up[i-1];
            sum[i]=sum[i-1]+up[i]-down[i];
        }
        if(sum[n-1]==m)
        {
            printf("%d\n",sum[x]);break;
        }
    }
    return 0;
}