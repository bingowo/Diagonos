#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int number;
    int point;
    int win;
    int lose;
} team;

int cmp(const void *a, const void *b)
{
    team *t1 = (team *)a;
    team *t2 = (team *)b;
    if (t1->point == t2->point)
    {
        if (t1->win == t2->win)
        {
            if (t1->lose == t2->lose)
            {
                return (t1->number - t2->number);
            }
            return (t1->lose - t2->lose);
        }
        return (t2->win - t1->win);
    }
    return (t2->point - t1->point);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (n != 0 || m != 0)
    {
        team arr[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i].number = i;
            arr[i].point = 0;
            arr[i].win = 0;
            arr[i].lose = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c > 0)
            {
                arr[a].point += 3;
                arr[b].point -= 1;
                arr[a].win += 1;
                arr[b].lose += 1;
            }
            else if (c < 0)
            {
                arr[b].point += 3;
                arr[a].point -= 1;
                arr[b].win += 1;
                arr[a].lose += 1;
            }
            else
            {
                arr[a].point += 1;
                arr[b].point += 1;
            }
        }
        qsort(arr + 1, n, sizeof(team), cmp);
        for (int i = 1; i < n; i++)
            printf("%d ", arr[i].number);
        printf("%d\n", arr[n].number);
        scanf("%d%d", &n, &m);
    }
    return 0;
}