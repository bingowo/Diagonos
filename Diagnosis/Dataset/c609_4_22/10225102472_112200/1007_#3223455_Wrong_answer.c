#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    long long A = *(long long*)a;
    long long B = *(long long*)b;
    long long number_A = 0;
    long long number_B = 0;
    long long d = 1;

    for (int i = 0; i < 64; i++)
    {
        if (A & d) number_A++;
        d <<= 1;
    }

    d = 1;

    for (int i = 0; i < 64; i++)
    {
        if (B & d) number_B++;
        d <<= 1;
    }

    if (number_A > number_B) return -1;
    if (number_B > number_A) return 1;
    if (number_A == number_B) return A - B;
}

int main()
{
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        long long x;
        long long array[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%lld", &x);
            array[i] = x;
        }

        qsort (array, N, sizeof(long long), cmp);

        printf("case #%d:\n", i);

        printf("%lld", array[0]);
        for (int i = 1; i < N; i++)
        {
            printf(" %lld", array[i]);
        }
        printf("\n");
    }

    return 0;
}
