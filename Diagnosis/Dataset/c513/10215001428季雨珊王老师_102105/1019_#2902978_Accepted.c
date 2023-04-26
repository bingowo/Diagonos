#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct group{
    int grade;
    int number;
    int win;
    int lose;
}*team;

int cmp(const void *a,const void *b){
    struct group *team1=(struct group *)a;
    struct group *team2=(struct group *)b;
    if((team1->grade)!=(team2->grade))
        return ((team2->grade)-(team1->grade));//降序
    else{
        if((team1->win)!=(team2->win))
            return ((team2->win)-(team1->win));//降序
        else{
            if((team1->lose)!=(team2->lose))
                return ((team1->lose)-(team2->lose));//升序
            else
                return((team1->number)-(team2->number));//升序
        }
    }
}

int main(){
    int n,m;//n代表球队数量，m代表比赛场数
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            return 0;
        int *a,*b,*c;
        a=(int *)malloc(sizeof(int)*m);
        b=(int *)malloc(sizeof(int)*m);
        c=(int *)malloc(sizeof(int)*m);
        team=(struct group *)malloc(sizeof(struct group)*n);
        for(int i=0;i<n;i++){
            team[i].number=i+1;
            team[i].grade=0;
            team[i].win=0;
            team[i].lose=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);//a，b表示球队编号；c表示比赛结果
            if(c[i]==1){
                for(int j=0;j<n;j++){
                    if(team[j].number==a[i]){
                        team[j].grade+=3;
                        team[j].win+=1;
                    }
                    if(team[j].number==b[i]){
                        team[j].grade-=1;
                        team[j].lose+=1;
                    }
                }
            }
            if(c[i]==-1){
                for(int j=0;j<n;j++){
                    if(team[j].number==a[i]){
                        team[j].grade-=1;
                        team[j].lose+=1;
                    }
                    if(team[j].number==b[i]){
                        team[j].grade+=3;
                        team[j].win+=1;
                    }
                }
            }
            if(c[i]==0){
                for(int j=0;j<n;j++){
                    if(team[j].number==a[i]){
                        team[j].grade+=1;
                    }
                    if(team[j].number==b[i]){
                        team[j].grade+=1;
                    }
                }
            }
        }
        qsort(team,n,sizeof(team[0]),cmp);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                printf("%d ",team[i].number);
            }
            else printf("%d\n",team[i].number);
        }
    }
}