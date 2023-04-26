#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b);

struct data
{
    int a;//球队编号1
    int b;//球队编号2
    int c;//胜负情况
    int d;//球队得分
};

struct final
{
    int teams;//球队 按序排
    int score;// 分数
    int wins;//记录失败场次
    int loses;//记录胜利场次
};
int main()
{
    struct data p[100];
    struct final p1[100];
    int n,m;//球队数量  比赛场数
    scanf("%d %d", &n, &m);
    while(m!=0&&n != 0){
        for(int i = 0;i < m;i++){
        scanf("%d %d %d", &p[i].a,&p[i].b,&p[i].c);
    }
        int ord = 1;
        for(int i = 0;i < n;i++){
            p1[i].teams = ord;
            ord++;
        }
        for(int i = 0;i < n;i++){
            p1[i].loses = 0;
            p1[i].score = 0;
            p1[i].wins = 0;
        }
        for(int i =0;i < m;i++){
            if(p[i].c == 1){int x = p[i].a;int y = p[i].b;p1[x-1].score += 3;p1[y-1].score -=1;p1[x-1].wins+=1;p1[y-1].loses+=1;}
            if(p[i].c == 0){int x = p[i].a;int y = p[i].b;p1[x-1].score += 1;p1[y-1].score +=1;}
            if(p[i].c == -1){int x = p[i].a;int y = p[i].b;p1[x-1].score -=1 ;p1[y-1].score +=3;p1[x-1].loses+=1;p1[y-1].wins+=1;}
        }   
        qsort(p1,n,sizeof(p1[0]),cmp);
        for(int i = 0;i < n;i++){
            printf("%d ", p1[i].teams);
        }
        printf("\n");
        scanf("%d %d",&n,&m);
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    struct final d1,d2;
    d1 = *((struct final*)a);
    d2 = *((struct final*)b);
    if(d1.score == d2.score){
        if(d1.wins == d2.wins){
            if(d1.loses == d2.loses){
                return d1.teams - d2.teams;
            }
            else{
                return d1.loses - d2.loses;
            }
        }
        else{
            return d2.wins - d1.wins;
        }
    }
    else{
        return d2.score - d1.score;
    }
}