#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct S
{
    char s[31];
    long long num;
};
int cmp(const void* _a, const void* _b)
{
    struct S a = *(struct S*)_a;
    struct S b = *(struct S*)_b;
    if (a.num == b.num) 
        return strcmp(a.s, b.s);
    else 
        return a.num - b.num;
}
int main()
{
    struct S A[101];
    for (int i = 0; i < 101; i++)
    {
        A[i].num = -1;//初始化
    }
    int k = 0;//k为元素个数
    while (scanf("%s", A[k].s) != EOF)
    {
        long long n = 0;
        for (int i = 0; i < (int)strlen(A[k].s); i++)
        {
            if (A[k].s[i] <= '9' && A[k].s[i] >= '0')
            {
                n = n * 10 + A[k].s[i] - 48;
            }
        }
        if (n>0)
            A[k].num = n;
        k++;
    }
    qsort(A, k, sizeof(A[0]), cmp);
    for (int i = 0; i < k; i++)
        printf("%s ", A[i].s);
    return 0;
}