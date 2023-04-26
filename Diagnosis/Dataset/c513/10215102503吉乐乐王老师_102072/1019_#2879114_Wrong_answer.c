#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int num;
    int win;
    int lose;
    int score;
}team;
int cmp(const void*a,const void *b){
    team x=*(team*)a;
    team y=*(team*)b;
    if(x.score==y.score){
        if(x.win==y.win){
            if(x.lose==y.lose)return x.num-y.num;
            return x.lose-y.lose;
        }
        return y.win-x.win;
    }
    return y.score-x.score;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2&&(n!=0&&m!=0)){
        team t[10];
        for(int i=0;i<n;i++){
            t[i].lose=0;t[i].score=0;t[i].win=0;
        }
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            t[a-1].num=a;t[b-1].num=b;
            if(c==1){t[a-1].score+=3;t[b-1].score-=1;t[a-1].win+=1;t[b-1].lose+=1;}
            if(c==-1){t[b-1].score+=3;t[a-1].score-=1;t[b-1].win+=1;t[a-1].lose+=1;}
            if(c==0){t[b-1].score+=1;t[a-1].score+=1;}
        }
        qsort(t,n,sizeof(t[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%d",t[i].num);
            if(i==n-1)putchar('\n');
            else putchar(' ');
        }
    }
}