#include <stdlib.h>
#include <stdlib.h>
typedef struct
{
    int bianhao;
    int win;
    int lose;
    int score;
}team;

int cmp(const void *a,const void *b)
{
    team *p1=(team*)a;
    team *p2 = (team*)b;
    if(p1->score!=p2->score){
        return p2->score - p1->score;
    }
    else if(p1->win != p2->win){
        return p2->win  - p1->win;
    }
    else if(p1->lose != p2->lose){
        return p1->lose - p2->lose;
    }
    else return p1->bianhao - p2->bianhao;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //team a[n];
    while(m&&n){
            team a[n];
    for(int i=0;i<m;i++){

        int x,y,c;
        for(int k=0;k<n;k++){
        a[k].score=0;
        a[k].win=0;
        a[k].lose=0;
        a[k].bianhao=k+1;
    }

        scanf("%d %d %d",&x,&y,&c);

        if(c==1){
            a[x-1].win++;
            a[y-1].lose++;
            a[x-1].score+=3;
            a[y-1].score-=1;
        }
        if(c==0){
            a[x-1].score+=1;
            a[y-1].score+=1;
        }
        if(c==-1){
            a[y-1].win++;
            a[x-1].lose++;
            a[y-1].score+=3;
            a[x-1].score-=1;
        }
    }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int j=0;j<n;j++)
        {
            printf("%d%c",a[j].bianhao, j == n - 1?'\n':' ');
        }
        scanf("%d %d",&n,&m);

}
}
