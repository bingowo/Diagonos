#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define N 100

//输出一个数中1的位数
int cot(long long int a)
{
    int sum = 0;
    unsigned long long int c;
    if(a < 0)
    {
        c  = (unsigned long long int)(~(-a) + 1);
    }
    else
        c = (unsigned long long int)a;
    do
    {
        if(c % 2 == 1)
        {
            sum++;
        }
    }while(c = c / 2);
    return sum;

}

//比较
int cmd(void*a,void*b)
{
    int A = *((int*)a);
    int B = *((int*)b);
    if(cot(A) != cot(B))
    {
        return cot(B) - cot(A);
    }
    else
    {
        return A - B;
    }

}

int main()
{
    int T;//循环次数
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        long long int *x = (long long int*)malloc(sizeof(long long int)*n);
        long long int* p = x;
        for(int j = 0;j < n;j++)
        {
            scanf("%lld",x++);
        }
        x = p;
        qsort(x,n,sizeof(long long int),cmd);
        for(int j = 0;j < n;j++)
        {
            printf("%lldd ",*x++);
        }
        printf("\n");
        x = p;
        free(x);
    }

    return 0;
}