#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int number;//编号
    int score;//积分
    int winnum;//或胜场数
}Qiudui;

int cmp(const void *a,const void *b)
{
    Qiudui *m,*n;
    m=(Qiudui *)a;
    n=(Qiudui *)b;
    if (m->score!=n->score){
        return m->score-n->score;
    } else{
        return m->winnum-n->winnum;
    }
}

int main()
{
    int n,m;
    int a,b,c;
    while (scanf("%d",&n)!=0 && scanf("%d",&m)!=0){
        Qiudui qiudui[n];
        for (int i = 0; i < n; ++i) {
            qiudui[i].number=i+1;
            qiudui[i].score=0;
            qiudui[i].winnum=0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d",&a,&b,&c);
            if (c==1) {
                qiudui[a].score+=3;
                qiudui[a].winnum+=1;
            }
            else if (c==-1){
                qiudui[b].score-=1;
            }
            else{
                qiudui[a].score+=1;
                qiudui[b].score+=1;
            }
        }
        qsort(qiudui,n,sizeof(qiudui[0]),cmp);
        for (int i = 0; i < n; ++i) {
            printf("%d ",qiudui[i].number);
        }
        printf("\n");
    }

    return 0;
}