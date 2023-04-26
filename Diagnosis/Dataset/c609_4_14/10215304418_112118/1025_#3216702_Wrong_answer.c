#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct ball{
    int score;
    int win;
    int fail;
    int draw;
    int name;
}team[123];

int cmp(const void* datai,const void* dataj){
    struct ball *dai=(struct ball *)datai;
    struct ball *daj=(struct ball *)dataj;
    if (dai->score==daj->score){
        if (dai->win==daj->win) {
            if (dai->fail==daj->fail){
                return dai->name-daj->name;
            }
            else return dai->fail-daj->fail;
        }
        else return daj->win-dai->win;
    }
    else return daj->score-dai->score;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while (n!=0 && m!=0){
        for (int i=1;i<=n;i++){
            team[i].score=0;
            team[i].win=0;
            team[i].fail=0;
            team[i].draw=0;
            team[i].name=i;
        }
        for (int i=1;i<=m;i++){
            int x,y,c;
            scanf("%d %d %d",&x,&y,&c);
            if (c==1){
                team[x].win++;
                team[y].fail++;
                team[x].score+=3;
                team[y].score-=1;
            }
            else if (c==0){
                team[x].draw++;
                team[y].draw++;
                team[x].score++;
                team[y].score++;
            }
            else if (c==-1){
                team[y].win++;
                team[x].fail++;
                team[y].score+=3;
                team[x].score-=1;
            }
        }
        qsort(team+1,n,sizeof(team[1]),cmp);
        for (int i=1;i<n;i++)
            printf("%d ",team[i].name);
        printf("%d\n",team[n].name);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
