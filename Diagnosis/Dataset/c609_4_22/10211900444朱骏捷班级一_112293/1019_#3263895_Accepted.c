#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *a, const void *b)
{

    int len_A = (int)(log10(abs(*(int *)a)) + 1e-8);
    int len_B = (int)(log10(abs(*(int *)b)) + 1e-8);
    if (len_A != len_B)
        return (len_B - len_A);
    else
        return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[1000010];
    int i = 0;
    while (scanf("%d", &arr[i]) == 1)
        i++;
    qsort(arr, i, sizeof(int), cmp);
    for (int j = 0; j < i; j++)
    {
        printf("%d", arr[j]);
        if (j != i - 1)
            printf(" ");
    }
    return 0;
}