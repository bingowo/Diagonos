#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long x, y;
}POINT;
long long xo, yo;
long long mymax(long long a, long long b)
{
    return a > b ? a : b;
}
int compar(const void* p1, const void* p2)
{
    POINT* a, * b;
    int flag = 0;
    a = *(POINT**)p1;b = *(POINT**)p2;
    long long step1, step2;
    step1 = mymax(llabs(a->x - xo), llabs(a->y - yo));
    step2 = mymax(llabs(b->x - xo), llabs(b->y - yo));
    if (step1 < step2) flag = -1;
    else if (step1 > step2) flag = 1;
    else
    {
        if (a->x < b->x) flag = -1;
        else if (a->x > b->x) flag = 1;
        else
        {
            if (a->y < b->y) flag = -1;
            else flag = 1;
        }
    }
    return flag;
}
int main()
{
    POINT** st;
    int n, i;
    scanf("%lld %lld", &xo, &yo);
    scanf("%d", &n);
    st = (POINT**)malloc(n * sizeof(POINT*));
    for (i = 0;i < n;i++)
    {
        st[i] = (POINT*)malloc(sizeof(POINT));
        scanf("%lld %lld", &st[i]->x, &st[i]->y);
    }
    qsort(st, n, sizeof(POINT*), compar);
    printf("%lld\n", mymax(llabs(st[0]->x - xo), llabs(st[0]->y - yo)));
    printf("%lld %lld", st[0]->x, st[0]->y);
    for (i = 0;i < n;i++) free(st[i]); free(st);
    return 0;
}
