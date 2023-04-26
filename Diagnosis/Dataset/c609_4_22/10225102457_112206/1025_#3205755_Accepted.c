#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num;
    int win;
    int lose;
    int score;
}TEAM;
int cmp(const void *p1, const void *p2);

int main(void)
{
    int n, m;
    int i = 0;
    int a,b,c;
    a = 0,b = 0,c = 0,n = 0,m = 0;

    while((scanf("%d%d",&n,&m)) != EOF){
        if(n == 0&&m == 0) break;
        TEAM cal[10];
        for(i = 0;i < n;i++){
            cal[i].lose = 0,cal[i].win = 0,cal[i].score = 0;
            cal[i].num = i;
        }

        for(i = 0;i < m;i++){
            scanf("%d%d%d",&a,&b,&c);
            switch (c)
            {
            case 1:
                cal[a-1].win++;
                cal[a-1].score +=3;
                cal[b-1].lose++;
                cal[b-1].score--;
                break;
            case -1:
                cal[b-1].win++;
                cal[b-1].score +=3;
                cal[a-1].lose++;
                cal[a-1].score--;
                break;
            case 0:
                cal[a-1].score++;
                cal[b-1].score++;
            default:
                break;
            }
        }

        qsort(cal,n,sizeof(TEAM),cmp);

        for(i = 0;i<n;i++)
            printf("%d ",cal[i].num +1);
        putchar('\n');
    }

    return 0;
}

int cmp(const void *p1, const void *p2)
{
    TEAM a = *(TEAM*)p1;
    TEAM b = *(TEAM*)p2;

    if(a.score != b.score) return b.score-a.score;
    else if(a.win != b.win) return b.win-a.win;
    else if(a.lose != b.lose) return a.lose-b.lose;
    else return a.num-b.num;
}