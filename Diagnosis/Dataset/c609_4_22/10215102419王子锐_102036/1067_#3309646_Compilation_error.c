#include<stdio.h>

int main()
{
    int up[21];// up数组存储每一站上车人数
    int down[21];// down数组存储每一站下车人数
    int sum[21];// sum数组存储每一站开出后的车上人数
    int a,n,m,x;
    scanf ("%d%d%d%d",&a,&n,&m,&x);
    up[1] = a; down[1] = 0;sum[1] = a;//第1站上车人数，下车人数和车上人数
    sum[2] = a;
    for (int t = 0; t <= m; ++t) //枚举t的取值,0~m
    {
        up[2] = t;
        down[2] = t;//第2站上车和下车人数
        for(int i = 3; i < n; ++i)
        {
            up[i] = up[i-1] + up[i-2];//第i站上车人数
            down[i] = up[i-1]; //第i站 下车人数
            sum[i] = sum[i-1] + up[i] - down[i];//第i站车上人数
        }
        if (sum[n-1] == m)
        {
            printf ("%d\n",sum[x]);break;
        }
    }
    return 0;
}
1