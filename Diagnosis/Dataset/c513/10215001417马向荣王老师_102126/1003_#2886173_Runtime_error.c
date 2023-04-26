#include<stdio.h>
#include<stdlib.h>
typedef struct NUM
{
    long long int a;//输入的整数
    int num;//1的个数
}NUM;

int cmp(const void *a,const void *b)
{
    NUM d1,d2;
    d1=*((NUM *)a);
    d2=*((NUM *)b);
    if(d2.num!=d1.num)//比1的多少
    {
        return d2.num-d1.num;
    }
    else //比数字大小
    {
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);//t个问题
    for(int i=0;i<t;i++)
    {
        NUM p[10001];
        int n=0;
        scanf("%d\n",&n);//每个问题里n个数
        for(int j=0;j<n;j++)
        {
            scanf("%lld",p[j].a);
            int d=1;
            p[i].num=0;
            for(int m=0;m<64;m++)//m是64位的位数,算每个元素1的个数
            {
            if(p[j].a&d!=0) p[j].num++;
            d=d<<1;
            }
            qsort(p,n,sizeof(p[0]),cmp);
            printf("case #%d:\n",i);
            for(int c=0;c<n-1;c++)
            {
                printf("%lld ",p[i].a);
            }
            printf("%lld\n",p[i].a);
        }
    }
    return 0;
}