#include <stdio.h>
#include <stdlib.h>

#define N 40

int input(int(*p)[N])  //传入数组指针;用二维数组存放数据，返回位数
{
    int i = 0;
    char c = 0;
    do
    {
        scanf("%d%c",&p[i++][N-1],&c);
    }
    while(c == ',');
    return i;
}

void mult_n(int a[], int n)  //大整数乘法：每一位均乘上要乘的数，再每一位%10做自己，/10进位
{
    int i = 0;
    for(i = N-1; i>0; i--)
    {
        a[i]*=n;
    }
    for(i = N-1; i>0; i--)
    {
        a[i-1] += a[i]/10;
        a[i] = a[i] % 10;
    }
}

void add(int d[], int dd[])  //大整数加法
{
    int i = 0;
    for(i = N-1; i>0; i--)
    {
        d[i] += dd[i];
        d[i-1] += d[i]/10;
        d[i] = d[i] % 10;
    }
}

int main()
{
    int pp[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int p[25][N] = {0};
    int d[N] = {0};
    //1.读入
    int num = 0;
    num = input(p);
    //2.计算位权
    int i = 0;
    int j = 0;
    for(i = 0; i<num; i++)
    {
        for(j = 0; j<num-1-i; j++)
        {
            mult_n(p[i], pp[j]);
        }
    //3.求和
        add(d, p[i]);
    }
    //4.输出
    i= 0;
    while(i < N &&d[i] == 0) i++; //跳过开头的0
    if(i>=N)  //全为0的特殊情况
    {
        printf("0\n");
    }
    else
    {
        while(i<N)
        {
            printf("%d",d[i++]);
        }
        printf("\n");
    }
    return 0;
}
