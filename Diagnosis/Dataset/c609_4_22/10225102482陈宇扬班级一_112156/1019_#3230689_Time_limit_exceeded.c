#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    int sign1 = 0, sign2 = 0;
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    int ln1 = 0, ln2 = 0;
    do
    {
        ln1++;
    } while (n1 /= 10);
    do
    {
        ln2++;
    } while (n2 /= 10);

    if (ln1 == ln2) //如果位数相同
        return *(int *)a - *(int *)b;
    else if (ln1 > ln2) //如果位数不同
        return -1;
    else if (ln1 < ln2)
        return 1;
}

int main()
{
    int n, len = 0;
    int nums[100001];
    while ((scanf("%d", &n)) != EOF)
        nums[len++] = n;
    for (int i = 0; i < len; i++)
        qsort(nums, len, sizeof(nums[0]), cmp);
    for (int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    system("pause");
    return 0;
}
