#include<stdio.h>
#include <stdlib.h>

typedef struct amin
{
    int order;
    int win;
    int lose;
    int point;
} team;

int cmp(const void* a,const void* b){
    team *p1 = (team*)a;
    team *p2 = (team*)b;
    if(p2->point == p1->point) {
        if (p2->win == p1->win) {
            if (p2->lose == p1->lose) {
                return p1->order - p2->order;
            }
            else return p1->lose - p2->lose;
        }
        else return p2->win - p1->win;
    }
    else return p2->point - p1->point;
}


int main() {
    for (int i = 0;; ++i) {
        int nub,cnt;
        scanf("%d %d",&nub,&cnt);
        if(nub == 0&&cnt == 0)break;
        team tea[nub];
        for (int j = 0; j < nub; ++j)
        {tea[j].point = 0;tea[j].win = 0;tea[j].lose = 0;tea[j].order = j + 1;}
        for (int j = 0; j < cnt; ++j) {
            int tea1,tea2,rand;
            scanf("%d %d %d",&tea1,&tea2,&rand);
            if(rand == 0){tea[tea1-1].point++;tea[tea2-1].point++;}
            else if(rand == 1){tea[tea1-1].point+=3;tea[tea1-1].win++;
                          tea[tea2-1].point--;tea[tea2-1].lose++;}
            else {tea[tea2-1].point+=3;tea[tea2-1].win++;
                  tea[tea1-1].point--;tea[tea1-1].lose++;}
        }
        qsort(tea,nub,sizeof(team),cmp);
        for (int j = 0; j < nub; ++j) {
            printf("%d(%d %d %d) ",tea[j].order,tea[j].point,tea[j].win,tea[j].lose);
        }printf("\n");
    }
}