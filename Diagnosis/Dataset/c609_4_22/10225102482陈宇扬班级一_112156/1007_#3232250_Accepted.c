#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long int

typedef struct NUM
{
    LL num;
    int ones;// 每个数中1的个数
}datasort;

int cmp(const void *a, const void *b)//比较规则
{
    datasort *d1 = (datasort*)a;
    datasort *d2 = (datasort*)b;
    if(d1->ones > d2->ones) return -1;
    else if(d1->ones < d2->ones) return 1;

    if(d1->num > d2->num) return 1;
    else if(d1->num <= d2->num) return -1;

}

int getone(LL num)//计算十进制数转成二进制数后1的个数
{
    int cnt = 0;
    for(int i = 0; i < 64; i++)
    {
        LL ans = num & ((LL) 1 << i);
        if(ans == (1LL << i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);//总问题数
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);//第几个问题
        datasort num[10000];
        for(int j = 0; j < N; j++)
        {
            scanf("%lld", &num[j].num);
            LL temp = num[j].num;
            num[j].ones = getone(temp);
        }
        qsort(num, N, sizeof(datasort), cmp);
        printf("case #%d:\n", i);
        for(int k = 0; k < N; k++)
            printf("%lld ", num[k].num);
        //printf("%lld", num[N-1].num);
        printf("\n");
    }
    return 0;
}



