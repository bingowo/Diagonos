#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long tag, points, win, lose;
}Team;

int cmp(const void *a, const void *b)
{
    Team *A = (Team *)a, *B = (Team *)b;
    if (A->points != B->points){
        if (B->points > A->points){
            return 1;
        }else{
            return -1;
        }
    }else if(A->win != B-> win){
        if (B->win > A->win){
            return 1;
        }else{
            return -1;
        }
    }else if(A->lose != B->lose){
        if (A->lose < B->lose){
            return -1;
        }else{
            return 1;
        }
    }else{
        if (A->tag < B->tag){
            return -1;
        }else{
            return 1;
        }
    }
}

int main()
{
    long long n, m, a, b, c, i;
    Team *T;
    while(scanf("%lld%lld", &n, &m) != EOF){
        if (n == 0 && m == 0){
            break;
        }else if(n != 0 && m == 0){
            printf("1 \n");
            continue;
        }
        T = (Team *)malloc(n * sizeof(Team));
        for (i = 0;i < n;i++){
            T[i].tag = i + 1;
            T[i].points = 0;
            T[i].win = 0;
            T[i].lose = 0;
        }
        for (i = 0;i < m;i++){
            scanf("%lld%lld%lld", &a, &b, &c);
            if (c == 1){
                T[a - 1].points += 3;
                T[a - 1].win += 1;
                T[b - 1].points -= 1;
                T[b - 1].lose += 1;
            }else if (c == -1){
                T[b - 1].points += 3;
                T[b - 1].win += 1;
                T[a - 1].points -= 1;
                T[a - 1].lose += 1;
            }else{
                T[a - 1].points += 1;
                T[b - 1].points += 1;
            }
        }
        qsort(T, n, sizeof(Team), cmp);
        for (i = 0;i < n;i++){
            printf("%lld ", T[i].tag);
        }
        printf("\n");
        free(T);
    }

    return 0;
}
