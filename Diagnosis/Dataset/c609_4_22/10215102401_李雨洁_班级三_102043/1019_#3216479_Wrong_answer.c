#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}//升序

int getnum(int a)
{
    int num = 1;
    while (!(a >= 0 && a <= 9))
    {
        a = a / 10;
        num++;
    }
    return num;
}
int main()
{
    int n=0;
    int a[1000001] = { 0 }, b[1000001] = { 0 };
    while (scanf("%d", &a[n]) != EOF)
    {
        n++;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        b[i] = getnum(a[i]);
    }
    qsort(b, n, sizeof(b[0]), cmp);
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] != b[i - 1])
            printf("%d ", a[i]);
        else
        {
            if (a[i] > a[i - 1])printf("%d ", a[i - 1]);
            else
                printf("%d ", a[i]);
        }
    }
    return 0;
}