#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int score;
    int win;
    int lose;
} TEAM;

int cmp (const void *a1, const void *b1)
{
    TEAM a = *(TEAM*)a1;
    TEAM b = *(TEAM*)b1;
    if (a.score != b.score){
        return b.score - a.score;
    }
    else if (a.win != b.win){
        return b.win - a.win;
    }
    else if (a.lose != b.lose){
        return a.lose - b.lose;
    }
    else{
        return a.num - b.num;
    }
}

int main()
{
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    while (!(n == 0 && m == 0)){
        TEAM *t = (TEAM*)malloc(sizeof(TEAM) * n);
        for (int i = 0; i < n; i ++){
            t[i].num = i + 1;
            t[i].score = 0;
            t[i].win = 0;
            t[i].lose = 0;
        }
        for (int i = 0; i < m; i ++){
            scanf("%d %d %d", &a, &b, &c);
            a --; b --;
            if (c == 1){
                t[a].score += 3; t[a].win ++;
                t[b].score --; t[b].lose ++;
            }
            else if (c == -1){
                t[a].score --; t[a].lose ++;
                t[b].score += 3; t[b].win ++;
            }
            else{
                t[a].score ++;
                t[b].score ++;
            }
        }
        qsort(t, n, sizeof(TEAM), cmp);
        for (int i = 0; i < n; i ++){
            printf("%d ", t[i].num);
        }
        printf("\n");
        free(t);
        scanf("%d %d", &n, &m);
    }
    return 0;
}