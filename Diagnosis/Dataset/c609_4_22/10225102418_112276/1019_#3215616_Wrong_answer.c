#include <stdio.h>
#include <stdlib.h>

int cnt(int a)
{
    int cnt = 0;
    if (a < 0)
    {
        ++cnt;
    }
    while (a != 0)
    {
        a /= 10;
        ++cnt;
    }
    return cnt;
}
int cmp(int *ap, int *bp)
{
    if (cnt(*ap) == cnt(*bp))
    {
        return *ap - *bp;
    }
    return cnt(*bp) - cnt(*ap);
}
int main()
{
    int map[100000] = {0};
    int i = 0;
    while (scanf("%d", &map[i]) != EOF)
    {
        ++i;
    }
    qsort(map, i, sizeof(int), cmp);
    for (int j = 0; j < i; ++j)
    {
        printf("%d ", map[j]);
    }
    return 0;
}