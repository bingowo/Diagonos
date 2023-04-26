#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct team{
    int id, score, win, notwin;
}T;

int cmp(const void* a, const void* b){
    T* x = (T*)a;
    T* y = (T*)b;
    int res = 0;
    if (x->score != y->score) res = x->score - y->score;
    else if (x->win != y->win) res = x->win - y->win;
    else if (x->notwin != y->notwin) res = y->notwin - x->notwin;
    else res = y->id - x->id;
    return -res;
}

int main(){
    int n, m, a, b, c;
    while (scanf("%d %d", &n, &m)){
        if (n == 0 && m == 0) break;
        T scores[12];
        for (int i = 0; i <= n; i++){
            scores[i].id = i;
            scores[i].score = 0;
            scores[i].win = 0;
            scores[i].notwin = 0;
        }
        for (int i = 1; i <= m; i++){
            scanf("%d %d %d", &a, &b, &c);
            switch(c){
                case 1:
                    scores[a].score += 3;
                    scores[a].win++;
                    scores[b].score -= 1;
                    scores[b].notwin++;
                    break;
                case -1:
                    scores[a].score -= 1;
                    scores[a].notwin++;
                    scores[b].score += 3;
                    scores[b].win++;
                    break;
                case 0:
                    scores[a].score += 1;
                    scores[b].score += 1;
                    break;
            }
        }
        qsort(scores+1, n, sizeof(T), cmp);
        for (int i = 1; i <= n; i++) printf("%d ", scores[i].id);
        printf("\n");   
    }
return 0;
}