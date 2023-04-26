#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int number;//编号
    int score;//积分
    int winnum;//或胜场数
    int losenum;//负场数
}Qiudui;

int cmp(const void *a,const void *b)
{
    Qiudui *pa = (Qiudui *)a;
    Qiudui *pb = (Qiudui *)b;
    if(pa->score!=pb->score){
        return pa->score>pb->score?-1:1;
    }
    else if(pa->winnum!=pb->winnum){
        return pa->winnum>pb->winnum?-1:1;
    }
    else if(pa->losenum!=pb->losenum){
        return pa->losenum>pb->losenum?1:-1;
    }
    else{
        return pa->number - pb->number;
    }
}

int main()
{
    int n,m;
    int a,b,c;
    scanf("%d %d",&n,&m);
    while (n!=0||m!=0){
        Qiudui qiudui[n];
        for (int i = 0; i < n; ++i) {
            qiudui[i].number=i+1;
            qiudui[i].score=0;
            qiudui[i].winnum=0;
            qiudui[i].losenum=0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d",&a,&b,&c);
            if (c==1) {
                qiudui[a-1].score+=3;
                qiudui[b-1].score-=1;
                qiudui[a-1].winnum++;
                qiudui[b-1].losenum++;
            }
            else if (c==-1){
                qiudui[b-1].score+=3;
                qiudui[a-1].score-=1;
                qiudui[b-1].winnum++;
                qiudui[a-1].losenum++;
            }
            else{
                qiudui[a-1].score+=1;
                qiudui[b-1].score+=1;
            }
        }
        qsort(qiudui,n,sizeof(qiudui[0]),cmp);
        for (int i = 0; i < n; ++i) {
            printf("%d%c",qiudui[i].number,i==n-1?'\n':' ');
        }
        scanf("%d %d",&n,&m);
    }

    return 0;
}