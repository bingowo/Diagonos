#include <stdio.h>

int main()//暴力枚举法
{
    int a;//始发站上车人数
    int n;//共有n个车站
    int m;//最后一站下车人数
    int x;//求第x站开出时车上人数
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int up[21],down[21],sum[21];
    up[1]=a;
    down[1]=0;
    sum[1]=a;
    for(int t=0;t<=m;t++)
    {
        up[2]=t;
        down[2]=t;
        sum[2]=a;
        for(int i=3;i<n;i++)//注意第n次不满足该条件
        {
            up[i]=up[i-1]+up[i-2];
            down[i]=up[i-1];
            sum[i]=sum[i-1]+up[i]-down[i];
        }
        if(sum[n-1]==m)
        {
            printf("%d\n",sum[x]);
            break;
        }
    }
    return 0;
}
