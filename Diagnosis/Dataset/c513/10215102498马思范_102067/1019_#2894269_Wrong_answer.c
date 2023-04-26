#include <stdio.h>
#include <stdlib.h>
struct team{
    int num;
    int score;
    int win;
    int lose;
}t[11];

int cmp1(const void* x,const void* y)
{
    struct team a=*(struct team*)x;
    struct team b=*(struct team*)y;
    if(a.score!=b.score)
        return b.score-a.score;
    else if(a.win!=b.win)
        return b.win-a.win;
    else if(a.lose!=b.lose)
        return a.lose-b.lose;
    else
        return a.num-b.num;
}

int main() {
    int n, m;
    int a, b, c;
    while (scanf("%d %d", &n, &m)) {
        if (n==0&&m==0) break;
        for (int j = 1; j <=n; j++) {
            t[j].score = 0;
            t[j].lose = 0;
            t[j].win = 0;
            t[j].num = j;
        }
        while(m--) {
            scanf("%d %d %d", &a, &b, &c);
            if (c == 1) {
                t[a].score += 3;
                t[a].win++;
                t[b].score -= 1;
                t[b].lose++;
            } else if (c == 0) {
                t[a].score++;
                t[b].score++;
            } else
            {
                t[a].score--;
                t[b].score += 3;
                t[a].lose++;
                t[b].win++;
            }
        }
        qsort(t, n, sizeof(t[0]), cmp1);
        for (int k = 1; k <=n; k++) {
            printf("%d%c", t[k].num, k != n ? ' ' : '\n');
        }
    }
    return 0;
}