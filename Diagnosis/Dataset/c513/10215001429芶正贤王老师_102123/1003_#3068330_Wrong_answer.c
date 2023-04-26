#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    long long int n;
    int binary[64];
    int num;
}STRUCT;

int cmp(const void *a,const void *b)
{
    STRUCT *x=(STRUCT *)a;
    STRUCT *y=(STRUCT *)b;
    if(x->num != y->num)//num降序
        return (y->num -x->num);
    else//本身值升序
        return (x->n - y->n);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        STRUCT CASE[N];
        
        for(int j=0;j<N;j++)//读入一组数据
        {
            scanf("%lld",&CASE[j].n);
            
            if(CASE[j].n>0 || CASE[j].n==0)//非负数
            {
                CASE[j].binary[63] = 0;
                CASE[j].num=0;
                long long int temp;
                temp=CASE[j].n;
                for(int r=0;r<63;r++)
                {
                    CASE[j].binary[r] = (int)(temp%2);
                    if(CASE[j].binary[r]==1)
                        CASE[j].num++;
                    temp=temp/2;
                }
            }
            else//负数
            {
                CASE[j].binary[63] = 1;
                CASE[j].num=1;
                long long int temp;
                temp = (-1)*CASE[j].n-1;
                for(int r=0;r<63;r++)
                {
                    CASE[j].binary[r] = abs((int)(temp%2)-1);
                    if(CASE[j].binary[r]==1)
                        CASE[j].num++;
                    temp=temp/2;
                    
                }
            }
        }
        
        qsort(CASE,N,sizeof(STRUCT),cmp);
        for(int j=0;j<N-1;j++)
        {
            printf("%lld ",CASE[j].n);
        }
        printf("%lld\n",CASE[N-1].n);
        
        
    }
    return 0;
    
}