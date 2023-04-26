#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_L 20

int cmp(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main()
{
    char order[27], s[MAX_N][MAX_L + 1];
    int i, j, k, n;
    scanf("%s", order);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        char str[MAX_L + 1];
        scanf("%s", str);
        for (j = 0; str[j]; ++j)
        {
            for (k = 0; order[k] != str[j]; ++k);
            s[i][j] = 'A' + k;
        }
        s[i][j] = '\0';
    }
    qsort(s, n, sizeof(s[0]), cmp);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; s[i][j]; ++j)
        {
            putchar(s[i][j] - 'A' + 'a');
        }
        putchar(' ');
    }
    putchar('\n');
    return 0;
}