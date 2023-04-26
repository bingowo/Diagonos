#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",c,1<<n); //直接利用位运算
    }
    return 0;
}
//位运算在2次幂运算的妙用
