#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team{
    int number;
    int goal;
    int win;
    int lose;
};

int compar(const void*a,const void*b){
    struct team t1,t2;
    t1=*((struct team*)a);
    t2=*((struct team*)b);
    if(t1.goal==t2.goal){
        if(t1.win==t2.win){
            if(t1.lose==t2.lose)return t1.number-t2.number;
            else return t1.lose-t2.lose;
        }else return t2.win-t1.win;
    }else return t2.goal-t1.goal;
}

int main(){
    int n,m,a,b,c;
    while(scanf("%d %d",&n,&m)!=EOF&&(n||m)){
        struct team teams[n];
        for(int i=0;i<n;i++){
            teams[i].number=i+1;
            teams[i].goal=0;
            teams[i].win=0;
            teams[i].lose=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1){
                teams[a-1].goal+=3;
                teams[a-1].win++;
                teams[b-1].goal--;
                teams[b-1].lose++;
            }else if(c==-1){
                teams[a-1].goal--;
                teams[a-1].lose++;
                teams[b-1].goal+=3;
                teams[b-1].win++;
            }else{
                teams[a-1].goal++;
                teams[b-1].goal++;
            }
        }
        qsort(teams,n,sizeof(teams[0]),compar);
        for(int j=0;j<n-1;j++)printf("%d ",teams[j].number);
        printf("%d\n",teams[n-1].number);
    }
    return 0;
}
