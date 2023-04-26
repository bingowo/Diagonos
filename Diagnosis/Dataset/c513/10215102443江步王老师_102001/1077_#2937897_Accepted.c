#include<stdio.h>
#include<stdlib.h>


int cmp(const void *_a,const void *_b);

int main()
{
    int m,n;
    int i,j;
    
    //数据输入
    scanf("%d",&m);
    
    int *A = (int *)malloc(sizeof(int)*m);
    for (i=0;i<m;i++)
    {
        scanf("%d",A+i);
    }
    
    scanf("%d",&n);
    
    int *B = (int *)malloc(sizeof(int)*n);
    for (i=0;i<n;i++)
    {
        scanf("%d",B+i);
    }
    qsort(B,n,sizeof(int),cmp);

    int t[1001]={0};//创建一个桶
    
    for (i=0;i<n;i++)
    {
        t[B[i]]++;
    }

    //第一部分输出，按顺序输出b数组中与a数组有重叠的数
    for (i=0;i<m;i++)
    {
        if (t[A[i]])
        {
            while (t[A[i]])
            {
                printf("%d ",A[i]);
                t[A[i]]--;
            }
        }
    }

    //第二部分输出，升序输出b数组中剩余的数
    for (i=0;i<n;i++)
    {
        if (t[B[i]])
        {
            while (t[B[i]])
            {
                printf("%d ",B[i]);
                t[B[i]]--;
            }
        }
    }

    free(A);free(B);
    return 0;
}

int cmp(const void *_a,const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return (*a-*b);
}