#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct SHU{long long int yuan;int diyi;}S;

int zhuanhuan(long long int a)
{
    int b;
    if(a<0)a=-a;
    while(a>=10)
    {
        a=a/10;
    }
    b=a;
    return b;
}

int cmp(const void *a,const void *b)
{
    S *p1=(S*)a;
    S *p2=(S*)b;
    if(p1->diyi<p2->diyi)
    {
        return 1;
    }
    else if (p1->diyi>p2->diyi)
    {
        return -1;
    }
    else if (p1->yuan<p2->yuan)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int count,count1,number;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&number);
        S A[10000];
        S* p=A;
        long long int a;
        for(int i=0;i<number;i++)
        {
            scanf("%lld",&a);
            A[i].yuan=a;
            A[i].diyi=zhuanhuan(a);
        }
        qsort(p,number,sizeof(A[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<number;i++)
    {
        if(i==number-1)
        {
            printf("%lld\n",A[i].yuan);
        }
        else
        printf("%lld ",A[i].yuan);
    }
    }
}
