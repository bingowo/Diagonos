#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
int score;
int tru;
int fail;
int ping;
int hao;
}com;
int cmp(const void* a,const void* b){
    com* aa=(com*)a;
    com* bb=(com*)b;
    if((*aa).score==(*bb).score)                                                                                                                                                    if((*aa).score == (*bb).score)
    {
        if((*aa).tru == (*bb).tru)
        {
            if((*aa).fail==(*bb).fail){return (*aa).hao<(*bb).hao;}
            return (*aa).fail<(*bb).fail;
        }
        return((*aa).tru < (*bb).tru);
    }
    return ((*aa).score < (*bb).score);
}
int main(){
    int n,m;//球队数量，比赛场数
    scanf("%d%d",&n,&m);
    com match[10];
    scanf("%d%d%d%d%d",&match->score,&match->tru,&match->fail,&match->ping,&match->hao);
    match->score=0;
    match->tru=0;
    match->fail=0;
    match->ping=0;
    for(int i=0;i<m;i++){
        int c,d,e;
        scanf("%d%d%d",&c,&d,&e);
        match[i].hao=i+1;
        //printf("%d\n",match[i].hao);
        if(e==0)match[c-1].score++,match[d-1].score++,match[c-1].ping++,match[d-1].ping++;
        else if(e==1)match[c-1].score=match[c-1].score+3,match[d-1].score--,match[d-1].fail++,match[c-1].tru++;
        else match[d-1].score=match[d-1].score+3,match[c-1].score--,match[c-1].fail++,match[d-1].tru++;;
    }
    qsort(match,n,sizeof(match[0]),cmp);
    for(int i=0;i<n;i++)printf("%d ",match[i].hao);
    return 0;
}
