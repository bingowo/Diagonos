#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define N 100

//数1的个数
long long int cot(long long int a) 
{
    long long int d = 1;
    int number = 0;
    for (int t = 0; t < 64; t++)
    {
        if (a & d) number++;
        d = d << 1;
    }
    return number;

}

//比较方法
long long int cmd(void*a,void*b)
{
    long long int A = *((long long int*)a);
    long long int B = *((long long int*)b);
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
    int T;
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
            printf("%lld ",*x++);
        }
        printf("\n");
        x = p;
        free(x);
    }

    return 0;
}
