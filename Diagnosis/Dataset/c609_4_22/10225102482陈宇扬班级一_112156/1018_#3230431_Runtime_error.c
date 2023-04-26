#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmpA(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    int s[10001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    qsort(s, n, sizeof(s[0]), cmpA);
    int sum_min = 0;
    for (int j = 0; j < n; j += 2)
    {
        sum_min += (s[j + 1] - s[j]);
    }
    printf("%d\n", sum_min);
    system("pause");
    return 0;
}

