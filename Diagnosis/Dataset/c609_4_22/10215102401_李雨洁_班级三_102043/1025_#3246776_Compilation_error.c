#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct team {
    int id;
    int score=0;
    int win=0;
    int f=0;
    int p=0;//平局
}T[11];

int cmp(const void* _a,const void* _b)
{
    struct team* a = (struct team*)_a;
    struct team* b = (struct team*)_b;
    if (a->score == b->score)
    {
        if (a->win == b->win)
        {
            if (a->f == b->f)
            {
                return a->id - b.id;
            }
            else
                return a->f - b.f;
        }
        else
            return b->win - a->win;
    }
    else 
        return b->score - a->score;
}

int main()
{
    int n, m;//n为球队数量，m为比赛场次
    scanf("%d %d", &n, &m);
    while ((n!=0) && (m != 0))
    {
        int a, b, c;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            T[a].id = a;
            T[b].id = b;
            if (c == 1)
            {
                T[a].score += 3;
                T[a].win += 1;
                T[b].score -= 1;
                T[b].f += 1;
            }
            else if (c == -1)
            {
                T[b].score += 3;
                T[b].win += 1;
                T[a].score -= 1;
                T[a].f += 1;
            }
            else
            {
                T[a].score += 1;
                T[b].score += 1;
                T[a].p += 1;
                T[b].p += 1;
            }
        }
        qsort(T, n, sizeof(T[0]), cmp);
        for (int z = 1; z <= n; z++)
            printf("%d ", T[z].id);
        printf("\n");
        scanf("%d %d", &n, &m);
    }
    return 0;
}