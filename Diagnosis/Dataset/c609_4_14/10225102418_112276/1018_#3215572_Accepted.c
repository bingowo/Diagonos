#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int cmp(int *a, int *b)
{
    return *a - *b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[100001] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < n; i += 2)
        sum += a[i + 1] - a[i];
    printf("%d", sum);
    return 0;
}