#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Team
{
    int win,lose,score,number;
};
struct Team team[11];

bool cmp(struct Team a,struct Team b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else if(a.win!=b.win)
        return a.win>b.win;
    else if(a.lose!=b.lose)
        return a.lose<b.lose;
    else
        return a.number<b.number;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int num1,num2,res;
        scanf("%d%d%d",&num1,&num2,&res);
        team[num1].number=num1;
        team[num2].number=num2;
        if(res==1)
        {
            team[num1].win+=1;
            team[num1].score+=3;
            team[num2].lose+=1;
            team[num2].score-=1;
        }
        else if(res==-1)
        {
            team[num2].win+=1;
            team[num2].score+=3;
            team[num1].lose+=1;
            team[num1].score-=1;
        }
        else
        {
            team[num1].score+=1;
            team[num2].score+=1;
        }
    }
    qsort(team,n,sizeof(struct Team),cmp);
    for(int i=0;i<n-1;i++)
    printf("%d ",team[i].number);
    printf("%d\n",team[n-1].number);
    return 0;
}
