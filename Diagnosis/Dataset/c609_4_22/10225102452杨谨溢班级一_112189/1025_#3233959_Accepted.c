#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int win;
    int fail;
    //int draw;// end in a draw 平局
    int score;
    int num;
}TEAM;

int cmp(const void* a, const void* b)
{
    TEAM A = *(TEAM*)a, B = *(TEAM*)b;
    if (A.score != B.score)  return B.score - A.score;
    if (A.win != B.win)  return B.win - A.win;
    if (A.fail != B.fail)  return A.fail - B.fail;
    return A.num - B.num;
}

int main()
{
    int n = 0, m = 0;
    while (scanf("%d %d",&n,&m))
    {
        if (n == 0 && m == 0)  break;
        TEAM* TT = (TEAM*)malloc((n) * sizeof(TEAM));
        for (int i = 0; i < n; ++i)
        {
            TT[i].win = 0;
            TT[i].fail = 0;
            TT[i].score = 0;
            TT[i].num = i+1;
        }
        while (m--)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            switch (c)
            {
            case 1: {
                TT[a-1].win++;
                TT[a-1].score += 3;
                TT[b-1].fail++;
                TT[b-1].score -= 1;
                break;
            }
            case -1: {
                TT[b-1].win++;
                TT[b-1].score += 3;
                TT[a-1].fail++;
                TT[a-1].score -= 1;
                break;
            }
            case 0: {
                TT[a-1].score++;
                TT[b-1].score++;
                break;
            }
            }
        }
        qsort(TT, n, sizeof(TT[0]), cmp);
        for (int i = 0; i < n; ++i)    printf("%d%c", TT[i].num, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
