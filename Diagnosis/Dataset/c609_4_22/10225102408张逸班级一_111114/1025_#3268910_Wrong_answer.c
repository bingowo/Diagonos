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
    while(m==0&&n!=0){
    for(int i=0;i<n;i++)
    printf("%d%c",i+1,i==n-1?'\n':' ');
    scanf("%d %d",&n,&m);
    }
    while(n==0&&m!=0){
        scanf("%d %d",&n,&m);
    }
    while(n!=0&&m!=0){
        team teams[n];
        for(int i=0;i<n;i++){
            teams[i].name=i+1;
            teams[i].point=0;
            teams[i].win=0;
            teams[i].lose=0;
        }
        while(m--){
         int a,b,c;
         scanf("%d %d %d",&a,&b,&c);
         switch(c){
             case 0:{
             teams[a-1].point+=1;
             teams[b-1].point+=1;
             break;}
             case 1:{
                 teams[a-1].point+=3;
                 teams[a-1].win+=1;
                 teams[b-1].point-=1;
                 teams[b-1].lose+=1;
                 break;
             }
             case -1:{
                 teams[b-1].point+=3;
                 teams[b-1].win+=1;
                 teams[a-1].point-=1;
                 teams[a-1].lose+=1;
                 break;
             }
             }
         }
         qsort(teams,n,sizeof(team),cmp);
         for(int i=0;i<n;i++){
             printf("%d%c",teams[i].name,i==n-1?'\n':' ');
         }
        scanf("%d %d",&n,&m);
    }
}