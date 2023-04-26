#include<stdio.h>
#include<stdlib.h>
typedef struct Team{
    int name;
    int point;
    int win;
    int lose;
}team;
int cmp(const void*a1,const void*a2){
    team*p1=(team*)a1;
    team*p2=(team*)a2;
    if(p1->point!=p2->point)return p2->point-p1->point;
    else if(p1->win!=p2->win)return p2->win-p1->win;
    else if(p1->lose!=p2->lose)return p1->lose-p2->lose;
    else return p1->name-p2->name;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=0||m!=0){
        team teams[n+1];
        for(int i=1;i<=n;i++){
            teams[i].name=i;
            teams[i].point=0;
            teams[i].win=0;
            teams[i].lose=0;
        }
        while(m--){
         int a,b,c;
         scanf("%d %d %d",&a,&b,&c);
         switch(c){
             case 0:{
             teams[a].point+=1;
             teams[b].point+=1;
             break;}
             case 1:{
                 teams[a].point+=3;
                 teams[a].win+=1;
                 teams[b].point-=1;
                 teams[b].lose+=1;
                 break;
             }
             case -1:{
                 teams[b].point+=3;
                 teams[b].win+=1;
                 teams[a].point-=1;
                 teams[a].lose+=1;
                 break;
             }
             }
         }
         qsort(teams+1,n,sizeof(team),cmp);
         for(int i=1;i<=n;i++){
             printf("%d%c",teams[i].name,i==n?'\n':' ');
         }
        scanf("%d %d",&n,&m);
        if(m==0&&n==0)return 0;
    }
}