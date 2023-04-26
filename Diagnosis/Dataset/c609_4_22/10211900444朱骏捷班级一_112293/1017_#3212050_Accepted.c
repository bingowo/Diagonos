#include <stdio.h>
#include <stdlib.h>
/*
int cmp(const void *a, const void *b)
{
    if (ch == 'A')
        return (*(int *)a - *(int *)b);
    else
        return (*(int *)b - *(int *)a);
}
*/
int main()
{
    int map[1001] = {};
    for (int i = 0; i < 1001; ++i)
        map[i] = 0;
    char ch;
    scanf("%c", &ch);
    int arr[110], i = 0, min = 1000, max = 0;
    while (scanf("%d", &arr[i]) == 1)
    {
        map[arr[i]] = 1;

        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
        i++;
    }
    // qsort(map, i, sizeof(int), cmp);
    if (ch == 'A')
    {
        int j = min;
        for (j; j < max; ++j)
        {
            if (map[j])
                printf("%d ", j);
        }
        printf("%d", max);
    }
    else
    {
        int j = max;
        for (j; j > min; --j)
        {
            if (map[j])
                printf("%d ", j);
        }
        printf("%d", min);
    }
    return 0;
}