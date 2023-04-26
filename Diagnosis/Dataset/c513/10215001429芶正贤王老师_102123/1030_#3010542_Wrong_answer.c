#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct 
{
    long long int digit;
    long long int first;
}DATA;

int cmp(const void*a,const void*b)
{   //first降序，本身值升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    if(x->first != y->first)
        return (int)(y->first - x->first);
    else 
        return (int)(x->digit - y->digit);
}

int main()
{
    int T;
    scanf("%d",&T);         //问题数
    int index;
    for(index = 0;index < T;index++)      //进入一个问题
    {
        int N;      //数据个数
        scanf("%d",&N);
        DATA CASE[N];
        int i,j;
        for(i=0;i<N;i++)            //对每个数据，录入结构体
        {
            scanf("%lld",&CASE[i].digit);
            long long int m;
            m = llabs(CASE[i].digit);
            if(m<10)
                CASE[i].first = m;
            else
            {
                while( (m /= 10) > 9);
            		CASE[i].first = m;
            }
        
        }
        qsort(CASE , N , sizeof(DATA) , cmp);
        printf("case #%d:\n",index);
        printf("%d\n",N);
        for(j=0;j<N-1;j++)
            printf("%lld ",CASE[j].digit);
        printf("%lld\n",CASE[N-1].digit);
        
        
    }
    return 0;
}