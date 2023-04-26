#include<stdio.h>
#define MaxN 10000
struct num1
{
    int count1;
    long long number;
};
void qort(struct num1* qrt,int len)
{
    struct num1 max=qrt[0];
    struct num1 num2;
    int i;
    for(i=1;i<len;i++)
    {
        if(max.count1<qrt[i].count1)
        {
            num2=max;
            max=qrt[i];
            qrt[i]=num2;
            
        }
        else if(max.count1==qrt[i].count1)
        {
            if(max.number>qrt[i].number)
            {
                num2=max;
            max=qrt[i];
            qrt[i]=num2;
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
    int count;
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
        qort(qrt,len);
        printf("case #%d:\n",i);
        for(j=0;j<len;j++)
        printf("%lld ",qrt[j].number);
        printf("\n");
    }
    return 0;
}