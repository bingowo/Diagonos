#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int num;
    int score;
    int win;
    int lose;
}team;

int cmp1(const void* x,const void* y)
{
    team *a=(team*)x;
    team *b=(team*)y;
    if(a->score!=b->score)
        return b->score-a->score;
    else if(a->win!=b->win)
        return b->win-a->win;
    else if(a->lose!=b->lose)
        return a->lose-b->lose;
    else
        return a->num-b->num;
}

int main() {
    int n, m;
    int a, b, c;
    team t[11];
    while (scanf("%d %d", &n, &m)) {
        if (n==0&&m==0) break;
        for (int j = 0; j <n; j++) {
            t[j].score = 0;
            t[j].lose = 0;
            t[j].win = 0;
            t[j].num = j;
        }
        while(m--) {
            scanf("%d %d %d", &a, &b, &c);
            if (c == 1) {
                t[a-1].score += 3;
                t[a-1].win++;
                t[b-1].score -= 1;
                t[b-1].lose++;
            } else if (c == 0) {
                t[a-1].score++;
                t[b-1].score++;
            } else
            {
                t[a-1].score--;
                t[b-1].score += 3;
                t[a-1].lose++;
                t[b-1].win++;
            }
        }
        qsort(t, n, sizeof(t[1]), cmp1);
        for (int k = 0; k <n; k++) {
            printf("%d%c",t[k].num+1,k !=(n-1) ? ' ' : '\n');
        }
    }
    return 0;
}

