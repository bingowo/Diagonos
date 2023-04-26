#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define N 100

int cot(int a)
{
    int sum = 0;
    unsigned int c;
    if(a < 0)
    {
        int b = a;
        c  = (unsigned)(~(-a) + 1);
    }
    else
        c = (unsigned)a;
    do
    {
        if(c % 2 == 1)
        {
            sum++;
        }
    }while(c = c / 2);
    return sum;

}

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
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int *x = (int*)malloc(sizeof(int)*(n + 1));
        int* p = x;
        for(int j = 0;j < n;j++)
        {
            scanf("%d",x++);
        }
        x = p;
        qsort(x,n,sizeof(int),cmd);
        for(int j = 0;j < n;j++)
        {
            printf("%d ",*x++);
        }
        printf("\n");
        x = p;
        free(x);
    }

    return 0;
}
