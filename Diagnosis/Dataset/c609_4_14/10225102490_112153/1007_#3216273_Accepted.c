#include <stdio.h>
#include <stdlib.h>
long long binary (long long n)//判断n中共有多少个1
{
    long long cont = 0;
    while (n)
    {
        n = (n-1) & n;//每次消去二进制中的一个1，共消去多少次就是有多少个1
        cont++;
    }
    return cont;
}

long long cmp (const void *a, const void *b)//改成比较类型
{
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (binary(x) != binary(y))
    {
        if (binary(x) > binary(y)) return -1;
        else return 1;
         //binary(y) - binary(x);//从大到小排序
    }
    else
    {
        if (x > y) return 1;
        else return -1;
        //return x - y;//若1位数相同则从小到大排列
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t = 0; t < T; t++)
    {
        int n;//待排列数个数
        scanf("%d",&n);
        long long *a = (long long *)malloc(sizeof(long long) * (n+1));
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a+1,n,sizeof(long long),cmp);
        printf("case #%d:\n",t);
        for (int i = 1; i <= n; i++)
        {
            printf("%lld ",a[i]);
        }
        printf("\n");
        free(a);
    }
    return 0;
}
