#include <stdio.h>
#include <stdlib.h>

typedef struct group_
{
    int number;
    int score;
    int win;
    int lose;
}Group;

int cmp(const void *_Group1,const void *_Group2)
{
    Group group1=*(Group *)_Group1;
    Group group2=*(Group *)_Group2;
    if(group1.score!=group2.score)
        return group1.score>group2.score?-1:1;
    else if(group1.win!=group2.win)
        return group1.win>group2.win?-1:1;
    else if(group1.lose!=group2.lose)
        return group1.lose>group2.lose?1:-1;
    else
        return group1.number>group2.number?1:-1;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=0)
    {
        Group *group=(Group *)malloc(n*sizeof(Group));
        for(int i=0;i<n;i++)
        {
            group[i].number=i+1;
            group[i].win=0;
            group[i].lose=0;
            group[i].score=0;
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;c;
            if(c==1)
            {
                group[a].win++;
                group[a].score+=3;
                group[b].lose++;
                group[b].score-=1;
            }
            else if(c==-1)
            {
                group[b].win++;
                group[b].score+=3;
                group[a].lose++;
                group[a].score-=1;
            }
            else
            {
                group[a].score++;
                group[b].score++;
            }
        }
        qsort(group,n,sizeof(Group),cmp);
        for(int i=0;i<n;i++)
            printf("%d ",group[i].number);
        printf("\n");
        free(group);
    }
    return 0;
}
