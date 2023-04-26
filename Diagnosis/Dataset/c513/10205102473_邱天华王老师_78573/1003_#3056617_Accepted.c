#include<stdio.h>
#include<stdlib.h>
typedef struct onei
{
    long long num;
    int one;
}onenum;

int cmp(const void* _a , const void* _b)
{
    onenum *a=(onenum*)_a;
    onenum *b=(onenum*)_b;
    if(a->one!=b->one) return (b->one - a->one);
    else
    {
        if(a->num>b->num) return 1;
        else return -1;
    }
}

int count1(long long num)
{
    int count = 0;
    long long d=1;
    for(int i=0;i<64;i++)
    {
        if(num&d) count++;
        d<<=1;
    }
    return count;
}


int main()
{
    int pro;
    scanf("%d",&pro);
    int count1(long long x);
    int cmp(const void* _a , const void* _b);
    for(int i=0;i<pro;i++)
    {
        int n;
        onenum s[10001];
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&s[j].num);
            s[j].one=count1(s[j].num);
        }

        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++)
        {

            printf("%lld ",s[q].num);
        }
        printf("\n");

    }
    return 0;
}
