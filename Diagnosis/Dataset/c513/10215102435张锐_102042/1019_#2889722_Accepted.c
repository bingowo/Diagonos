#include <stdio.h>
#include <stdlib.h>

struct team
{
    int index;
    int win;
    int lose;
    int draw;
} teams[10] = {0};

int cmp(const void *_a, const void *_b)
{
    struct team a = *(struct team *)_a, b = *(struct team *)_b;
    int a_score = a.win * 3 + a.draw - a.lose, b_score = b.win * 3 + b.draw - b.lose;
    if (a_score > b_score)
        return -1;
    else if (a_score < b_score)
        return 1;
    else
    {
        if (a.win > b.win)
            return -1;
        else if (a.win < b.win)
            return 1;
        else
        {
            if (a.lose < b.lose)
                return -1;
            else if (a.lose > b.lose)
                return 1;
            else
            {
                if (a.index < b.index)
                    return -1;
                else if (a.index > b.index)
                    return 1;
                else
                    return 0;
            }
        }
    }
}

int main()
{
    int n, m;
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            teams[i].index = i + 1;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            if (c == 1)
                teams[a - 1].win++, teams[b - 1].lose++;
            else if (c == -1)
                teams[a - 1].lose++, teams[b - 1].win++;
            else
                teams[a - 1].draw++, teams[b - 1].draw++;
        }

        qsort(teams, n, sizeof(struct team), cmp);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", teams[i].index);
            teams[i].win = 0, teams[i].lose = 0, teams[i].draw = 0;
        }
        printf("\n");
    }

    return 0;
}