#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int A = *(int*)a;
    int B = *(int*)b;

    int temp_A = A;
    int temp_B = B;

    while (temp_A != 0 && temp_B != 0)
    {
        temp_A /= 10;
        temp_B /= 10;
    }

    if (temp_B == 0)
        return -1;
    else if (temp_A == 0)
        return 1;
    else
        return A - B;
}

int main()
{
    int *x = (int*)malloc(sizeof(int) * 1000000);
    int number = 0;

    for (int i = 0; ; i++)
    {
        scanf("%d", &x[i]);
        number++;
        if (getchar() == '\n')
            break;
    }

    qsort(x, number, sizeof(int), cmp);

    printf("%d", x[0]);

    for (int i = 1; i < number; i++)
    {
        printf(" %d", x[i]);
    }

    return 0;
}