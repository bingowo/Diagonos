#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int getnum(int a)//得到整数a的位数，a可为负数
{
    int num = 1;
    while (!(a >= 0 && a <= 9))
    {
        a = a / 10;
        num++;
    }
    return num;
}
struct S
{
    int aa;
    int num;
}s[1000000];
int cmp(const void* _a, const void* _b)
{
    struct S* a = (struct S*)_a;
    struct S* b = (struct S*)_b;
    if (a->num != b->num)
        return b->aa - a->aa;
    else
        return a->num - b->num;
}
int main()
{
    int a;
    int i = 0;
    while ((scanf("%d", &a)) != EOF)
    {
        s[i].aa = a;
        s[i].num = getnum(a);
        i++;
    }
    qsort(s, i, sizeof(s[0]), cmp);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", s[j].aa);
    }

    return 0;
}