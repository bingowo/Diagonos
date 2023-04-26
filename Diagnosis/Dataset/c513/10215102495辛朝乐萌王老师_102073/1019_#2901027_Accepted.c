#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int score;
    int win;
    int lose;
}Info;

int cmp(const void *a,const void *b)
{
    Info *pa = (Info *)a;
    Info *pb = (Info *)b;
    if(pa->score!=pb->score){
        return pa->score>pb->score?-1:1;
    }
    else if(pa->win!=pb->win){
        return pa->win>pb->win?-1:1;
    }
    else if(pa->lose!=pb->lose){
        return pa->lose>pb->lose?1:-1;
    }
    else{
        return pa->id - pb->id;
    }
}

int main(void)
{
    int n,m;
    int t1,t2,c;
    scanf("%d %d",&n,&m);
    while (n!=0 || m!=0) {
        Info team[n];
        for (int i=0; i<n; i++) {
            team[i].id=i+1;
            team[i].score= team[i].win=team[i].lose=0;
        }
        for (int i=0; i<m; i++) {
            scanf("%d %d %d",&t1,&t2,&c);
            if(c==1){
                team[t1-1].score += 3;
                team[t1-1].win++;
                team[t2-1].score -=1;
                team[t2-1].lose++;
            }
            else if(c==0){
                team[t1-1].score+=1;
                team[t2-1].score+=1;
            }
            else if(c==-1){
                team[t2-1].score+=3;
                team[t2-1].win++;
                team[t1-1].score -=1;
                team[t1-1].lose++;
            }
        }
        qsort(team, n, sizeof(Info), cmp);
        for (int i=0; i<n; i++) {
            printf("%d%c",team[i].id,i==n-1?'\n':' ');
        }
        scanf("%d %d",&n,&m);
    }
    return 0;
}
