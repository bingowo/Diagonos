#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct number
{
    unsigned long long num;
    int digit;
} Number;

int cmp(const void *a, const void *b)
{
    if (((Number *)a)->digit != ((Number *)b)->digit)
        return (((Number *)b)->digit - ((Number *)a)->digit);
    else
        return (((Number *)a)->num - ((Number *)b)->num);
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
        for (int k = 0; k < N - 1; k++)
        {
            printf("%llu ", arr[k].num);
        }
        printf("%llu\n", arr[k].num);
        free(arr);
    }
    return 0;
}