#include<stdio.h>
int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d\n",&a,&n,&m,&x);
    int up[21];
    int down[21];
    int sum[21];
    up[1]=a;down[1]=0;sum[1]=a;
    for(int i=0;i<=m;i++)
    {
        up[2]=0;
        down[2]=0;
        for(int i=3;i<=n-1;i++)
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