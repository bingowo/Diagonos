#include<stdio.h>
#include<stdlib.h>

struct number
{
    long long n;
    long long num2;
};

int cmpfunc(const void * a, const void * b)
{
    if((*(struct number*)a).num2!=(*(struct number*)b).num2)
        return ((*(struct number*)b).num2-(*(struct number*)a).num2);
    else if((*(struct number*)b).n>=(*(struct number*)a).n)return -1;
    else return 1;
}

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        struct number number1[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&number1[j].n);
            number1[j].num2=0;
            long long digit=number1[j].n;
            while(digit)
            {
                digit=digit&(digit-1);
                number1[j].num2++;
            }
        }
        qsort(number1,N,sizeof(struct number),cmpfunc);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("%lld ",number1[j].n);
        }
        printf("\n");
    }
}