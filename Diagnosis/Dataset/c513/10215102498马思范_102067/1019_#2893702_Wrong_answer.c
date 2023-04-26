#include <stdio.h>
#include <stdlib.h>
struct team{
    int num;
    int score;
    int win;
    int lose;
}t[11];
int cmp(struct team a,struct team b)
{
    if(a.score!=b.score)
    {return a.score-b.score;}
    else if(a.win!=b.win)
    {return a.win-b.win;}
    else if(a.lose!=b.lose)
    {return b.lose-a.lose;}
    else if(a.num!=b.num)
    {return b.num-a.num;}
}
int main() {
    int n, m;
    int a, b, c;
    while (scanf("%d%d", &n, &m)) {
        for (int j = 0; j < n; j++) {
            t[j].score = 0;
            t[j].lose = 0;
            t[j].win = 0;
            t[j].num = j;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if (c == 1) {
                t[a].score += 3;
                t[a].win++;
                t[b].score -= 1;
                t[b].lose++;
            } else if (c == 0) {
                t[a].score++;
                t[b].score++;
            } else if (c == -1) {
                t[a].score--;
                t[b].score += 3;
                t[a].lose++;
                t[b].win++;
            }
        }
        qsort(t, n, sizeof(t[0]), cmp);
        for (int k = 0; k < n; k++) {
            printf("%d%c", t[k].num, k != n - 1 ? ' ' : '\n');
        }
        return 0;
    }
}