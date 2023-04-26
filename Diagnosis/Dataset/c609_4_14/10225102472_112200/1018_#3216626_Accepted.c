#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int sum1 = 0, sum2 = 0;
    int n;
    int *x;

    scanf("%d", &n);

    x = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    qsort (x, n, sizeof(int), cmp);

    for (int i = 0; i < n; i = i + 2)
    {
        sum1 += x[i];
    }

    for (int i = 1; i < n; i = i + 2)
    {
        sum2 += x[i];
    }

    printf ("%d", sum2 - sum1);

    return 0;
}
