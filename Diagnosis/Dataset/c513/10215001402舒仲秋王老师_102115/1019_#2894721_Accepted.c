#include <stdio.h>
#include <stdlib.h>
struct data
{
    int name;
    int score;
    int win;
    int fail;
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    if(d1.score>d2.score) t=-1;
    else if(d1.score<d2.score) t=1;
    else
    {
        if(d1.win>d2.win) t=-1;
        else if(d1.win<d2.win) t=1;
        else
        {
            if(d1.fail<d2.fail) t=-1;
            else if(d1.fail>d2.fail) t=1;
            else t=d1.name-d2.name;
        }
    }

    return t;
}
int main()
{
 for(;;)
    {
        int cs,ds,i;
        scanf("%d %d",&ds,&cs);
        if(ds==0&&cs==0) break;
        struct data game[ds];
        for(i=0;i<ds;i++) game[i].name=i+1,game[i].score=0,game[i].win=0,game[i].fail=0;
        for(i=0;i<cs;i++)
        {
            int mid1,mid2,mid3;
            scanf("%d %d %d",&mid1,&mid2,&mid3);
            if(mid3==0) game[mid1-1].score+=1,game[mid2-1].score+=1;
            else if(mid3==1) game[mid1-1].score+=3,game[mid1-1].win+=1,game[mid2-1].score-=1,game[mid2-1].fail+=1;
            else game[mid1-1].score-=1,game[mid1-1].fail+=1,game[mid2-1].score+=3,game[mid2-1].win+=1;
        }
        qsort(game,ds,sizeof(game[0]),cmp);
        for(i=0;i<ds-1;i++) printf("%d ",game[i].name);
        printf("%d\n",game[i].name);

    }
    return 0;
}
