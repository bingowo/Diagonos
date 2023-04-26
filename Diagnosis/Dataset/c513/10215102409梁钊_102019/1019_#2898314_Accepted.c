#include<stdio.h>
#include<stdlib.h>

typedef struct rank{
    int number;
    int score;
    int win;
    int lose;
} rank ;
int cmp(const void* _a,const void* _b)
{
    rank* a = (rank*)_a ; rank* b = (rank*)_b ;
    if((*a).score != (*b).score) {
        return (*b).score - (*a).score > 0 ? 1 : -1 ;}
    if((*a).win != (*b).win) {
        return (*b).win - (*a).win > 0 ? 1 : -1 ;}
    if((*a).lose != (*b).lose) {
        return (*a).lose - (*b).lose > 0 ? 1 : -1 ;}
    return (*a).number - (*b).number > 0 ? 1 : -1 ;
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) && n!=0){
        rank rank[n];
        for(int i=0;i!=n;i++){
            rank[i].number=i+1;
            rank[i].score=0;
            rank[i].win=0;
            rank[i].lose=0;
        }
        int a,b,c;
        for(int j=0;j!=m;j++){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1){
                rank[a-1].win++;rank[b-1].lose++;
                rank[a-1].score+=3;rank[b-1].score-=1;
            }
            else if(c==-1){
                rank[b-1].win++;rank[a-1].lose++;
                rank[b-1].score+=3;rank[a-1].score-=1;
            }
            else{
                rank[a-1].score++;rank[b-1].score++;
            }
        }
        qsort(rank,n,sizeof(rank[0]),cmp);
        for(int k=0;k!=n;k++) printf("%d ",rank[k].number);
        printf("\n");
    }
}
