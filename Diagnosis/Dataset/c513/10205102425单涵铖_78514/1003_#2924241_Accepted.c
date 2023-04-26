#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long int a;
    int number;
}data;

int cmp(const void *a,const void *b)
{
    data m,n;
    m = *((data*)a);
    n = *((data*)b);
    if(m.number != n.number)    return n.number - m.number;
    else    
    {
        if(m.a>n.a) return 1;
        else return -1;
    }
}



int main()
{
    int t,n; //t为输入的数据数，n为每个数据里的问题数；
    data N[10001];
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&N[j].a);
        }
        for(int j=0;j<n;j++)
        {
            int m=0;
            long long int d = 1; //d为诱饵，m为二进制数里的1的个数
            for(int g=0;g<64;g++)
            {
                if((N[j].a&d))
                {
                    m++;
                }
                d = d << 1;
            }
            N[j].number = m;
        }
        qsort(N,n,sizeof(N[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%lld ",N[j].a);
        }
        printf("\n");
    }
    return 0;
}