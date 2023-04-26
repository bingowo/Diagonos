#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int coeb[21] = { 0,0,0,0,1 }, coea[21] = { 0,1,0,1,0,1 };
int deltacoea(int n)
{
    if (n <= 5)
        return coea[n];
    if (coea[n] == 0)
        coea[n] = deltacoea(n - 1) + deltacoea(n - 2);
    return coea[n];
}
int deltacoeb(int n)
{
    if (n <= 4)
        return coeb[n];
    if (coeb[n] == 0)
        coeb[n] = deltacoeb(n - 1) + deltacoeb(n - 2);
    return coeb[n];
}
int main(void)
{
    int a, n, m, x, i, numa, numb, b, ans;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    numa = numb = 0;
    for (i = 0;i < n;i++)
    {
        numa += deltacoea(i);
        numb += deltacoeb(i);
    }
    b = (m - numa * a) / numb;
    numa = numb = 0;
    for (i = 0;i <= x;i++)          //最后一站没有上人，但是求的是要包括第x站上的人
    {
        numa += deltacoea(i);
        numb += deltacoeb(i);
    }
    ans = numa * a + numb * b;
    printf("%d", ans);
    return 0;
}