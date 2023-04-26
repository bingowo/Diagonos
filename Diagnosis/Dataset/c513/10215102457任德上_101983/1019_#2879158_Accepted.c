#include<stdio.h>
#include<stdlib.h>
struct team{
    int num;
    int score;
    int win;
    int lose;
};
int cmp(const void *a,const void *b){
    struct team m,n;
    m=*((struct team*)a);
    n=*((struct team*)b);
    if(n.score>m.score)return 1;
    if(n.score==m.score&&n.win>m.win)return 1;
    if(n.score==m.score&&n.win==m.win&&n.lose<m.lose)return 1;
    if(n.score==m.score&&n.win==m.win&&n.lose==m.lose&&n.num<m.num)return 1;
    return -1;
}
int main(){
    int m,n,a,b,c;
    scanf("%d%d",&n,&m);
    while(m!=0||n!=0){
        struct team k[n];
        for(int i=0;i<n;i++)k[i].num=i+1,k[i].score=0,k[i].win=0,k[i].lose=0;
        while(m-->0){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){k[a-1].score+=3,k[a-1].win+=1,k[b-1].score-=1,k[b-1].lose+=1;}
            else if(c==-1){k[a-1].score-=1,k[a-1].lose+=1,k[b-1].score+=3,k[b-1].win+=1;}
            else {k[a-1].score+=1,k[b-1].score+=1;}
        }
        qsort(k,n,sizeof(struct team),cmp);
        for(int i=0;i<n-1;i++)printf("%d ",k[i].num);
        printf("%d\n",k[n-1].num);
        scanf("%d%d",&n,&m);
    }
    return 0;
}




