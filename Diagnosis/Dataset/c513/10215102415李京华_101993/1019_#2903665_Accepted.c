#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    int win;
    int lose;
    int id;
}Team;

int cmp(const void *_a, const void *_b) {
    Team a = *(Team *)_a;
    Team b = *(Team *)_b;
    if (a.score != b.score)
        return b.score - a.score;
    if (a.win != b.win)
        return b.win - a.win;
    if (a.lose != b.lose)
        return a.lose - b.lose;
    return a.id - b.id;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n != 0) {
        Team team[n];
        int i;
        for (i = 0; i < n; i++){
            team[i].id = i + 1;
            team[i].score = 0;
            team[i].win = 0;
            team[i].lose = 0;
        }

        //input
        for (i = 0; i < m; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c == 1) {
                team[a-1].score += 3;
                team[a-1].win++;

                team[b-1].score--;
                team[b-1].lose++;
            }
            else if (c == -1) {
                team[a-1].score--;
                team[a-1].lose++;

                team[b-1].score += 3;
                team[b-1].win++;                
            }
            else {
                team[a-1].score++;
                team[b-1].score++;
            }
        }

        //sort
        qsort(team, n, sizeof(team[0]), cmp);

        //output
        for (i = 0; i < n - 1; ++i)
            printf("%d ", team[i].id);
        printf("%d\n", team[i].id);

        //loop
        scanf("%d%d", &n, &m);
    }
    
    
    return 0;
}