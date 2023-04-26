#include <stdio.h>
#include <stdlib.h>
int binary (int n)//判断n中共有多少个1
{
    int cont = 0;
    while (n)
    {
        n = (n-1) & n;//每次消去二进制中的一个1，共消去多少次就是有多少个1
        cont++;
    }
    return cont;
}

long long cmp (const void *a, const void *b)
{
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (binary(x) != binary(y))
    {
        return binary(y) - binary(x);//从大到小排序
    }
    else
    {
        return x - y;//若1位数相同则从小到大排列
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
            scanf("%d",&a[i]);
        }
        qsort(a+1,n,sizeof(int),cmp);
        printf("case #%d:\n",t);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        free(a);
    }
    return 0;
}
