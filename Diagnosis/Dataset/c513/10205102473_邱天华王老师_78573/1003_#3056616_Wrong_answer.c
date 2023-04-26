#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BIN
{
    int one;
    long long num;
}bin;

int cmp(const void *q1, const void *q2)
{
    bin *p1 = (bin *)q1;
    bin *p2 = (bin *)q2;
    if(p1->one > p2->one) return -1;
    if(p1->one < p2->one) return 1;
    if(p1->num > p2->num) return 1;
    else if(p1->num <= p2->num)return -1;
}



int getone(long long a)
{
    int one = 0;
    for(int i = 0; i < 64; i++)
    {
        if((a & ((long long ) 1 << i)) == (1LL << i))
        {one++;}
    }

    return one;
}

int main()
{
    int total;
    scanf("%d",&total);
    for(int i = 0; i < total; i++)
    {
        int allN;
        bin arr[10010];
        scanf("%d",&allN);
        for(int j = 0; j < allN; j++)
        {
            scanf("%d",&arr[j].num);
            long long temp = arr[j].num;
            arr[j].one = getone(temp);
        }

        qsort(arr,allN,sizeof(bin),cmp);
        printf("case #%d:\n",i);

        for(int j = 0; j < allN; j++)
        {
            printf("%d ",arr[j].num);
        }
        printf("\n");
    }
    return 0;
}
