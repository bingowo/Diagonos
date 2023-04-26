#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 15  //the Maxnum of team

typedef struct{
    int score;
    int win_t,lose_t;
    int code;
}team;

int cmp(const void* a,const void* b)
{
    team *ta=(team*)a;team *tb=(team*)b;
    if(ta->score!=tb->score)return ta->score<tb->score?1:-1;
    else if(ta->win_t!=tb->win_t)return ta->win_t<tb->win_t?1:-1;
    else if(ta->lose_t!=tb->lose_t)return ta->lose_t>tb->lose_t?1:-1;
    else if(ta->code!=tb->code)return ta->code>tb->code?1:-1;
    else return 0;
}

int main()
{
    while(1){
        int team_num,race_num;
        scanf("%d%d\n",&team_num,&race_num);
        if(!team_num&&!race_num)break;
        team t[N];
        for(int i=0;i<N;++i){
            t[i].code=t[i].lose_t=t[i].win_t=0;
            t[i].code=i;
        }
        int t1,t2,r_res;
        for(int j=0;j<race_num;++j){
            scanf("%d%d%d",&t1,&t2,&r_res);
            if(r_res==1){
                t[t1-1].win_t++;t[t1-1].score+=3;
                t[t2-1].lose_t++;t[t2-1].score--;
            }
            else if(r_res==-1){
                t[t2-1].win_t++;t[t2-1].score+=3;
                t[t1-1].lose_t++;t[t1-1].score--;
            }
            else{
                t[t1-1].score++;t[t2-1].score++;
            }
        }
        qsort(t,team_num,sizeof(t[0]),cmp);
        for(int k=0;k<team_num;++k){
            printf("%d%c",t[k].code+1,k==team_num-1?'\n':' ');
        }
    }
    return 0;
}
