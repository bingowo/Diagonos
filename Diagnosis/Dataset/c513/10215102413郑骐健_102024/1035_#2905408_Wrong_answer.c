#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  cylinder
{
    long long int minus;
    long long int ra;//半径
    long long int high;
    int flag;
}cy;

int cmp(const void* p1, const void* p2)
{
    cy* p_1 = *(cy**)p1;
    cy* p_2 = *(cy**)p2;
    if (p_1->ra < p_2->ra)return 1;
    else if (p_1->ra == p_2->ra)return (p_1->high < p_2->high) ? -1 : 1;
    else return -1;
}
int cmp2(const void* p1, const void* p2)
{
    cy* p_1 = *(cy**)p1;
    cy* p_2 = *(cy**)p2;
    if (p_1->minus > p_2->minus)return 1;
    else if (p_1->minus == p_2->minus)return (p_1->ra > p_2->ra) ? 1 : -1;
    else return -1;
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    cy* s[1001];

    cy* c[1001];
    int point1 = 0;
    int point2 = 0;
    for (int i = 0;i < m;i++)
    {
        s[i] = (cy*)malloc(sizeof(cy) + 100);
        scanf("%lld%lld", &s[i]->ra, &s[i]->high);
        s[i]->minus = 2 * (s[i]->high) * (s[i]->ra);
        s[i]->flag = 1;
    }


    int num = m;
    qsort(s, m, sizeof(cy*), cmp);
    for (int o = 0;o < m;o++)
    {
        c[o] = s[o];
    }
    qsort(s, m, sizeof(cy*), cmp2);
    for (;num > n;num--)
    {
        while (c[point1]->flag == 0)point1++;
        while ((s[point2] == c[point1]) || (s[point2]->flag == 0))point2++;


        if (s[point2]->minus >= c[point1]->minus + (c[point1]->ra) * (c[point1]->ra) - (c[point1 + 1]->ra) * (c[point1 + 1]->ra))
        {
            c[point1]->flag = 0;
            point1++;
        }
        else
        {
            s[point2]->flag = 0;
            point2++;
        }

    }
    int g = 0;
    while (c[g]->flag == 0)g++;
    long long int res = 0;
    res += (c[g]->ra) * (c[g]->ra);
    for (;g < m;g++)
    {
        if (c[g]->flag)res += c[g]->minus;
    }
    printf("%lld", res);
    for (int p = 0;p < m;p++)
    {
        free(c[p]);
    }


    return 0;
}