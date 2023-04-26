#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int team;
    int score;
    int win;
    int defeat;
}Teams;
int cmp(const void* p1,const void*p2){
    Teams *a =(Teams *)p1;
    Teams *b =(Teams *)p2;
    if(a->score != b->score){
        return  b->score - a->score;
    }
    if(a->win != b->win){
        return b->win - a->win;
    }
    if(a->defeat != b->defeat){
        return a->defeat - b->defeat;
    }
    return a->team-b->team;
}
int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)&& ((m||n)!=0)){
        Teams s[n];
        for(int j=0;j<n;j++){
            s[j].team=j+1;
            s[j].score=0;
            s[j].win=0;
            s[j].defeat=0;
        }
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c ==1){
                s[a-1].score += 3;
                s[a-1].win++;
                s[b-1].score-- ;
                s[b-1].defeat++;
            }
            else if(c==-1) {
                s[b-1].score +=3;
                s[b-1].win++;
                s[a-1].score--;
                s[a-1].defeat++;
            }
            else{
                s[a-1].score++;
                s[b-1].score++;
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%d%c",s[i].team,i==n-1?'\n':' ');
        }
    }
    return 0;
}
