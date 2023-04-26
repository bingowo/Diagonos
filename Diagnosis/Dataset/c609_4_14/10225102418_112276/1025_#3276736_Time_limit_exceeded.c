#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct team
{
    int num;
    int score;
    int win;
    int fail;
} T;
int cmp(const void *a, const void *b)
{
    T *ap = (T *)a;
    T *bp = (T *)b;
    if (ap->score != bp->score)
    {
        return bp->score - ap->score;
    }
    else
    {
        if (ap->win != bp->win)
        {
            return bp->win - ap->win;
        }
        else
        {
            if (ap->fail != bp->fail)
            {
                return ap->fail - bp->fail;
            }
            else
            {
                return ap->num - bp->num;
            }
        }
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    T *S = (T *)malloc(sizeof(T) * n);
    for (int i = 0; i < n; ++n)
    {
        S[i].num = i;
        S[i].win = 0;
        S[i].fail = 0;
        S[i].score = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c == 1)
        {
            S[a - 1].score += 3;
            ++S[a - 1].win;
            ++S[b - 1].fail;
        }
        else if (c == -1)
        {
            S[b - 1].score += 3;
            ++S[b - 1].win;
            ++S[a - 1].fail;
        }
        else
        {
            ++S[a - 1].score;
            ++S[b - 1].score;
        }
    }
    qsort(S, n, sizeof(T), cmp);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", S->num + 1);
    }
    return 0;
}