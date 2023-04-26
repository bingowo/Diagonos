#include <stdio.h>
#include <stdlib.h>

int getnum(int a)//得到整数a的位数，不计符号位
{
    int num = 1;
    if (a < 0)
    {
        while (!(a >= 0 && a <= 9))
        {
            a = a / 10;
            num++;
        }
        return num-1;
    }
    else
    {
        while (!(a >= 0 && a <= 9))
        {
            a = a / 10;
            num++;
        }
        return num ;
    }      
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
        return b->num - a->num;
    else
        return a->aa - b->aa;
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