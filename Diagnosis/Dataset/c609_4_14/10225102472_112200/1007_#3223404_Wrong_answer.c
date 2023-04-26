#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    int temp_A = A;
    int temp_B = B;
    int number_A = 0;
    int number_B = 0;

    while (temp_A != 0)
    {
        if (temp_A % 2 == 1) number_A++;
        temp_A /= 2;
    }
    if (A < 0) number_A = 65 - number_A;
    if (A % 2 == 0) number_A--;

    while (temp_B != 0)
    {
        if (temp_B % 2 == 1) number_B++;
        temp_B /= 2;
    }
    if (B < 0) number_B = 65 - number_B;
    if (B % 2 == 0) number_B--;

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
            printf("% lld", array[i]);
        }
        printf("\n");
    }

    return 0;
}
