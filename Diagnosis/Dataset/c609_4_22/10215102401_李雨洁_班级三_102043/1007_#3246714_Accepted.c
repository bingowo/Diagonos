#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
struct my_sort
{
    long long num;  // 输入的数
    int cnt;  // '1'的个数
};

int cmp(const void* a, const void* b)
{
    struct my_sort d1,d2;
    d1=*((struct my_sort *)a);
    d2=*((struct my_sort *)b);
    if(d2.cnt!=d1.cnt) return d2.cnt-d1.cnt;
    else
    {
        if(d1.num>d2.num) 
            return 1;
        else 
            return -1;
    }
}
int main()
{
    int T; 
    scanf("%d",&T);
    for(int i = 0; i < T; ++i)
    {
        int N; 
        scanf("%d",&N);
        struct my_sort S[MAXN];
        for(int j = 0; j < N; ++j)
        {
            scanf("%lld",&S[j].num);
            S[j].cnt = 0;
            long long and_num = 1, k = 0;
            while(k < 64)
            {
                if(S[j].num & and_num) S[j].cnt++;
                and_num = and_num * 2;
                k++;
            }
        }
        qsort(S, N, sizeof(S[0]),cmp);
        printf("case #%d:\n",i);
        int j;
        for(j = 0; j < N - 1; j++)
            printf("%lld ",S[j].num);
        printf("%lld\n",S[j].num);
    }
    return 0;
}