#include<stdio.h>
#include<string.h>

int a[100007],len;

void multiply(int n)
{
    int num = 0,tmp;
    for(int i = 0; i < len; i++)
    {
        tmp = a[i]*n + num;//数组中每个数都乘一下这个数；
        a[i] = tmp%10;//余数留下；
        num = tmp/10;//10的倍数留给下一个数加；
    }
    while(num)//若num不为0需要加长数组，且余数和10的倍数需要处理；
    {
        a[len] = num%10;
        num /= 10;
        len++;
    }
}

int main()
{
    int n,k,j,cas,i;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        a[0] = 1;
        len = 1;
        for(j = 2; j <= n; j++)
            multiply(j);
        for(k = 0; a[k] == 0; k++);
        printf("case #%d:\n",i);
        printf("%d\n",k);
    }
    return 0;
}


