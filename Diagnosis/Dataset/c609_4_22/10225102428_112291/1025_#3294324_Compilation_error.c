#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
int score;
int tru;
int fail;
int ping;
int hao;
}com;
int cmp(const void* a,const void* b){
    struct com* aa=(struct com*)a;
    struct com* bb=(struct com*)b;
    if((*aa).score == (*bb).score)
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
    scanf("%d%d%d%d%d%d",&match,&com.score,&com.fail,&com.tru,&com.ping,&com.score);
    for(int j=1;j<n+1;j++)com[j].hao=j;
    for(int i=0;i<m;i++){
        int c,d,e;
        scanf("%d%d%d",&c,&d,&e);
        if(c==0)com[c-1].score++,com[d-1].score++,com[c-1].ping++,com[d-1].ping++;
        else if(c==1)com[c-1].score=com[c-1].score+3,com[d-1].score--,com[d-1].fail++,com[c-1].tru++;
        else com[d-1].score=com[d-1].score+3,com[c-1].score--,com[c-1].fail++,com[d-1].tru++;;
    }
    qsort(match[10],n,sizeof(int),cmp);
    for(int i=0;i<n;i++)printf("%d ",match[i]);
    return 0;
}
