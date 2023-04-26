#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    int name;       //队名
    int score;
    int wintime;
    int losetime;
}sw;
int compar(const void *p1,const void *p2);
int main()
{
    int m,n,a,b,c,i;
    sw* team;
    do
    {
        scanf("%d",&m);
        scanf("%d",&n);
        team=(sw*)malloc((m+1)*sizeof(sw));
        for(i=1;i<=m;i++)
        {
            team[i].name=i;
            team[i].score=0;
            team[i].wintime=0;
            team[i].losetime=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                team[a].score+=3;
                team[a].wintime+=1;
                team[b].score-=1;
                team[b].losetime+=1;
            }
            else if(c==-1)
            {
                team[b].score+=3;
                team[b].wintime+=1;
                team[a].score-=1;
                team[a].losetime+=1;
            }
            else
            {
                team[a].score+=1;
                team[b].score+=1;
            }
        }
        qsort(team+1,m,sizeof(sw),compar);
        for(i=1;i<=m;i++)
        {
            printf("%d\n",team[i].name);
        }
    }while(m!=0||n!=0);
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    sw *a,*b;
    a=(sw*)p1;
    b=(sw*)p2;
    if((*a).score>(*b).score)             //.优先级大于*
        flag=-1;
    else if((*a).score<(*b).score)
        flag=1;
    else
    {
        if((*a).wintime>(*b).wintime)
            flag=-1;
        else if((*a).wintime<(*b).wintime)
            flag=1;
        else
        {
            if((*a).losetime<(*b).losetime)
                flag=-1;
            else if((*a).losetime>(*b).losetime)
                flag=1;
            else
            {
                if((*a).name<(*b).name)
                    flag=-1;
                else
                    flag=1;
            }
        }
    }
    return flag;
}
