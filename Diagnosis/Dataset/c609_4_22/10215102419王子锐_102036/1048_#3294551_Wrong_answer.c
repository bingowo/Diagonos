#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    long long fib[121] = {0, 1};
    for (int i = 2; i <= 120; i++) 
    {
        fib[i] = fib[i-1] + fib[i-2];  // 计算斐波那契数列的值
    }

    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,fib[n]);
    }
}