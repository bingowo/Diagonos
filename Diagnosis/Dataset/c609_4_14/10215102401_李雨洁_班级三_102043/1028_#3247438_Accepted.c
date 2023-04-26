#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* _a, const void* _b)//整型二维数组的排序
{
    int* a = (int*)_a; int* b = (int*)_b;
    int i = 0;
    for (; (a[i] != -1) && (b[i] != -1); i++)
    {
        if (a[i] > b[i]) return -1;
        else if (a[i] < b[i]) return 1;
    }
    if ((a[i] == -1) && (b[i] == -1)) return 0;
    if (b[i] == -1) return -1;
    return 1;
}
int main()
{
    int t;int n;
    scanf("%d", &t);
    int num[1001][51];
    for (int q = 0; q < t; q++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int a = 1;
            for (int j = 0; a != -1; j++)
            {
                scanf("%d", &a);
                num[i][j] = a;
            }
        }
        qsort(num, n, sizeof(num[0]), cmp);
        for (int i = 0; i < n; i++)
        {
            if (num[i][0] != -1)
            {
                printf("%d", num[i][0]);
                for (int j = 1; num[i][j] != -1; j++)
                    printf(" %d", num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}