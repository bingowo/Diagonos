#include<stdio.h>
#define MaxN 10000
struct num1
{
    int count1;
    long long number;
};
void qort(struct num1** qrt,int len)
{
    int i,j;
    struct num1 num2;
    for(j=0;j<len-1;j++)
    {for(i=0;i<len-1-j;i++)
    {
        if(qrt[i]->count1<qrt[i+1]->count1)
        {
            num2=*qrt[i];
            *qrt[i]=*qrt[i+1];
            *qrt[i+1]=num2;
        }
        else if(qrt[i]->count1==qrt[i+1]->count1)
        {
            if(qrt[i]->number>qrt[i+1]->number)
            {
                num2=*qrt[i];
                *qrt[i]=*qrt[i+1];
                *qrt[i+1]=num2;
            }
        }
    }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int i,j;
    long long num;
    int count=0;
    struct num1 qrt[MaxN];
    for(i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lld",&num);
            int sn;
            for(sn=0;sn<64;sn++)
            {
                if((num>>sn)&1)
                count++;
            }
            qrt[j].count1=count;
            qrt[j].number=num;
        }
        int len=j;
        qort(&qrt,len);
        printf("case #%d:\n",i);
        for(j=0;j<len;j++)
        printf("%lld ",qrt[j].number);
        printf("\n");
    }
    return 0;
}