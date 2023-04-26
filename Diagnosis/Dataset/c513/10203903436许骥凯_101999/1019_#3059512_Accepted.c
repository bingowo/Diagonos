#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int win;
    int lost;
    int score;
} team;

int cmp(const void* v1, const void* v2) {
    team t1 = *(team*)v1, t2 = *(team*)v2;
    if (t1.score == t2.score) {
        if (t1.win == t2.win) {
            if (t1.lost == t2.lost)
                return t1.id - t2.id;
            return t1.lost - t2.lost;
        }
        return t2.win - t1.win;
    }
    return t2.score - t1.score;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n != 0 || m != 0) {
        team Teams[10];
        for (int i = 0; i != n; ++i) {
            Teams[i].id = i + 1;
            Teams[i].score = Teams[i].lost = Teams[i].win = 0;
        }
        for (int i = 0; i != m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c == 0) {
                ++Teams[a - 1].score;
                ++Teams[b - 1].score;
            } else if (c == 1) {
                ++Teams[a - 1].win;
                ++Teams[b - 1].lost;
                Teams[a - 1].score += 3;
                Teams[b - 1].score -= 1;
            } else if (c == -1) {
                ++Teams[a - 1].lost;
                ++Teams[b - 1].win;
                Teams[a - 1].score -= 1;
                Teams[b - 1].score += 3;
            }
        }
        qsort(Teams, n, sizeof(Teams[0]), cmp);
        for (int i = 0; i != n; ++i)
            printf("%d%c", Teams[i].id, i == n - 1 ? '\n' : ' ');
        scanf("%d%d", &n, &m);
    }
    return 0;
}