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
    if((*aa).score==(*bb).score)                                                                                                                                                   if((*aa).score == (*bb).score)
    {
        if((*aa).tru == (*bb).tru)
        {
            if((*aa).fail==(*bb).fail){return (*aa).hao<(*bb).hao;}
            else return (*aa).fail<(*bb).fail;
        }
        else return((*aa).tru < (*bb).tru);
    }
    else return ((*aa).score < (*bb).score);
}
int main(){
    int n,m;//球队数量，比赛场数
    while(scanf("%d%d",n,m)){
            if(n==0&&m==0)break;
            com match[n+1];
            scanf("%d%d%d%d%d",&match->score,&match->tru,&match->fail,&match->ping,&match->hao);
            for(int i=0;i<10;i++){
                match[i].score=0;
                match[i].tru=0;
                match[i].fail=0;
                match[i].ping=0;
                match[i].hao=i+1;
            }
            for(int i=0;i<m;i++){
            int c,d,e;
            scanf("%d%d%d",&c,&d,&e);
        //printf("%d",match[i].hao);
            if(e==0)match[c-1].score++,match[d-1].score++,match[c-1].ping++,match[d-1].ping++;//printf("%d",match[c-1].score);
            else if(e==1)match[c-1].score=match[c-1].score+3,match[d-1].score--,match[d-1].fail++,match[c-1].tru++;
            else if(e==-1)match[d-1].score=match[d-1].score+3,match[c-1].score--,match[c-1].fail++,match[d-1].tru++;;
            }
            qsort(match,n,sizeof(match),cmp);
            int i=0;
            for(i=0;i<n-1;i++)printf("%d ",match[i].hao);
            printf("%d",match[i].hao);
    }
            return 0;
}
