#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int win;
    int lose;
    int score;
    int num;
}T;

int cmp(const void* m, const void* n) {
    T *a=(T*)m, *b=(T*)n;
    if(a->score != b->score)
        return b->score - a->score;
    else{
        if(a->win != b->win)
            return b->win - a->win;
        else {
            if(a->lose != b->lose)
                return a->lose - b->lose;
            else return a->num - b->num;
        }
    }
}    //结果是正的说明b赢
int main()
{
   int n, m;
    scanf("%d %d",&n, &m);
    while (n || m) {
        T team[11];
        for(int i=1; i<=n; ++i){
            team[i].num = i;
            team[i].win = team[i].lose = team[i].score = 0;
        }
        int a, b, c;
        for(int i=0; i<m; ++i) {
            scanf("%d %d %d",&a, &b, &c);
            if(c == 1) {
                ++team[a].win; ++team[b].lose;
                team[a].score+=3;
                --team[b].score;
            }
            else if(c == -1) {
                ++team[b].win; ++team[a].lose;
                team[b].score+=3;
                --team[a].score;
            }
            else {
                ++team[a].score;
                ++team[b].score;
            }
        }
        qsort(&team[1],n,sizeof(T),cmp);
        for(int i=1; i<=n; ++i)
            printf("%d%s",team[i].num,i<n?" ":"\n");
        scanf("%d %d",&n, &m);
    }
    return 0;
}