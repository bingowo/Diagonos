#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct aline
{
    long long num[51];//每行的数字
    int length;
}line;

int cmp(const void *_a, const void *_b);

int main()
{
    int T,N;
    int i,j,k;
    int len=0;
    long long *p=NULL;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d",&N);
        line *L = (line *)malloc(sizeof(line)*N);
        //数组L存放每行的信息
        for (j=0;j<N;j++)//读入0到N-1行的数据
        {
            p = L[j].num;
            len=0;
            while (scanf("%lld",p) == 1)
            {
                if (*p != -1)
                {
                    p++;
                    len++;
                }
                else{
                    L[j].length=len;
                    break;
                }
            }
        }
        qsort(L,N,sizeof(line),cmp);
        for (j=0;j<N;j++)
        {
            p=L[j].num;
            while (*p != -1)
            {
                printf("%lld ",*p);
                p++;
            }
            putchar('\n');
        }
    }
    return 0;
}


int cmp(const void *_a, const void *_b)
{
    line *a=(line *)_a;
    line *b=(line *)_b;
    int i=0;
    int len1,len2;
    int flag=-1;
    len1=(*a).length;len2=(*b).length;
    while (i<len1 && i<len2)
    {
        if ((*b).num[i] > (*a).num[i])
        {
            flag=1;
            return flag;
        }
        else{
            i++;
        }
    }
    if (!(i<len1 && i<len2))
    {
        if (len2 < len1)
        {
            flag=1;
        }
    }
    return flag;
}