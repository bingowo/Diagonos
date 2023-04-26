#include <stdio.h>
#include <stdlib.h>

typedef struct number
{
    unsigned long long num;
    int digit;
} Number;

int cmp(const void *a, const void *b)
{
    if (((Number *)a)->digit != ((Number *)b)->digit)
        return (((Number *)b)->digit - ((Number *)a)->digit);
    else if ((long long)((Number *)a)->num < (long long)((Number *)b)->num)
        return -1;
    else if ((long long)((Number *)a)->num > (long long)((Number *)b)->num)
        return 1;
    else
        return 0;
}

int cal(unsigned long long num)
{
    int cnt = 0;
    while (num)
    {
        cnt += num & 1;
        num >>= 1;
    }
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        Number *arr = (Number *)malloc(N * sizeof(Number));
        int val;
        unsigned long long temp;
        for (int j = 0; j < N; j++)
        {
            scanf("%llu", &temp);
            val = cal(temp);
            arr[j] = (Number){temp, val};
        }
        qsort(arr, N, sizeof(Number), cmp);
        printf("case #%d:\n", i);
        int k = 0;
        for (k; k < N - 1; k++)
        {
            printf("%lld ", arr[k].num);
        }
        printf("%lld\n", arr[k].num);
        free(arr);
    }
    return 0;
}