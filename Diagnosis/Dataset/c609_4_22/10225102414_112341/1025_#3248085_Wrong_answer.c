#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tag, points, win;
}Team;

int cmp(const void *a, const void *b)
{
    Team *A = (Team *)a, *B = (Team *)b;
    if (A->points != B->points && A->win == B->win){
        return B->points - A->points;
    }else if(A->win != B-> win){
        return B->win - A->win;
    }else{
        return A->tag - B->tag;
    }
}

int main()
{
    int n, m, a, b, c, i;
    Team *T;
    while(scanf("%d%d", &n, &m)){
        if (n == 0 || m == 0){
            break;
        }
        T = (Team *)malloc(n * sizeof(Team));
        for (i = 0;i < n;i++){
            T[i].tag = i + 1;
            T[i].points = 0;
            T[i].win = 0;
        }
        for (i = 0;i < m;i++){
            scanf("%d%d%d", &a, &b, &c);
            if (c == 1){
                T[a - 1].points += 3;
                T[a - 1].points += 1;
                T[b - 1].points -= 1;
            }else if (c == -1){
                T[b - 1].points += 3;
                T[b - 1].points += 1;
                T[a - 1].points -= 1;
            }else{
                T[a - 1].points += 1;
                T[b - 1].points += 1;
            }
        }
        qsort(T, n, sizeof(Team), cmp);
        for (i = 0;i < n;i++){
            printf("%d", T[i].tag);
            if (i == n - 1){
                printf("\n");
            }else{
                printf(" ");
            }
        }
    }
    return 0;
}