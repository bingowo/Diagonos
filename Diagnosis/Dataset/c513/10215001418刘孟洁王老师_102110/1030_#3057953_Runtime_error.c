#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    long long int num;int max;
}high;

int cmp(const void*a,const void*b)
{
    high c=*(high*)a;
    high d=*(high*)b;
    if(c.max>d.max) return -1;
    else if(c.max<c.max) return 1;
    else return c.num-d.num;
}

int main()
{
    int T,N,i,k;
    long long int j,a;
    high *b;//别忘记*
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        b=(high*)malloc(sizeof(high)*N);
        for(k=0;k<N;k++)
        {
            scanf("%lld",&b[k].num);
            a=b[k].num;
            if(llabs(a)>=10)//long long int的绝对值llabs（)
            {
                while(llabs(a)>=10)
                {
                    a=a/10;
                    j=a;
                }
            }
            else j=a;
            b[j].max=llabs(j);
        }
        qsort(b,N,sizeof(high),cmp);
        printf("case #%d:\n",i);
        for(k=0;k<N;k++)
            printf("%lld%c",b[k].num,k==N-1?'\n':' ');
        free(b);
    }
    return 0;
}
