#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

struct Team{
    int score;
    int win;
    int lose;
    int equal;
    int teamNum;
};

int main()
{
    int n,m;
    scanf("%d %d",&n, &m);
    do{
        if(n == 1){
            printf("1\n");
            continue;
        }
        struct Team t[n];
        for(int i = 0; i < n; i++){
            t[i].score = 0;
            t[i].win = 0;
            t[i].lose = 0;
            t[i].equal = 0;
            t[i].teamNum = i + 1;
        }
        for(int i = 0; i < m; i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c == 1){
                t[a - 1].win = t[a - 1].win + 1;
                t[b - 1].lose = t[b - 1].lose + 1;
            }else if(c == -1){
                t[b - 1].win = t[b - 1].win + 1;
                t[a - 1].lose = t[a - 1].lose + 1;
            }else if(c == 0){
                t[a - 1].equal = t[a - 1].equal + 1;
                t[b - 1].equal = t[b - 1].equal + 1;
            }
        }
        for(int i = 0; i < n; i++){
            t[i].score = t[i].win * 3 - t[i].lose + t[i].equal;
        }
        qsort(t,n,sizeof(t[0]),cmp);
        for(int i = 0; i < n-1; i++){
            printf("%d ",t[i].teamNum);
        }
        printf("%d\n",t[n-1].teamNum);
        scanf("%d %d",&n, &m);
    }while(n != 0);
    return 0;
}


int cmp(const void *a, const void *b){
    struct Team t1;
    struct Team t2;
    t1 = (*(struct Team *)a);
    t2 = (*(struct Team *)b);
    if(t1.score != t2.score){
        return t2.score - t1.score;
    }else if(t1.win != t2.win){
        return t2.win - t1.win;
    }else if(t1.lose != t2.lose){
        return t1.lose - t2.lose;
    }else{
        return t1.teamNum - t2.teamNum;
    };
}

