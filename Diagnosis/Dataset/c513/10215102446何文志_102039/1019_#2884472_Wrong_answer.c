#include <stdio.h>
#include <stdlib.h>
typedef struct Team
{
    int score;
    int win;
    int fail;
    int num;
}team;



void cmp(const void* a,const void* b)
{
    team A = *(team*)a, B = *(team*)b;
    //return -1;
    if(A.score != B.score){return A.score - B.score;}
    else
    {
        if(A.win != B.win){return A.win - B.win;}
        else
        {
            if(A.fail != B.fail){return A.fail - B.fail;}
            else
            {
                return A.num - B.num;
            }
        }
    }
}

int main()
{

    int n = 0,m = 0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        //printf("%d %d\n",n,m);
        if((n==0)&&(m==0)){continue;}
        //team初始化

        team teams[n];
        memset(teams,0,n*sizeof(team));
        for(int i = 0;i<n;i++){teams[i].num = i+1;}
        //
        //printf("size %d\n",sizeof(team));

        //for(int j = 0;j<m;j++)
        //{
        //    printf("%d ",teams[j].num);
        //}
        //printf("\n");

        for(int i = 0;i<m;i++)
        {
            int a = 0,b = 0,c = 0;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                teams[a-1].score+=3;teams[a-1].win+=1;
                teams[b-1].score-=1;teams[b-1].fail+=1;
            }

            else if(c==-1)
            {
                teams[a-1].score-=1;teams[a-1].fail+=1;
                teams[b-1].score+=3;teams[b-1].win+=1;
            }
            else
            {
                teams[a-1].score+=1;
                teams[b-1].score+=1;
            }
        }
        qsort(teams,n,sizeof(team),cmp);

        for(int j = 0;j<n;j++)
        {
            //printf("team[%d]:score = %d,win = %d,fail = %d,num = %d\n",j,team[j].score,team[j].win,team[j].fail,team[j].num);
            //printf("team[%d]: score = %d, win = %d, fail = %d\n",teams[j].num,teams[j].score,teams[j].win,teams[j].fail);
            printf("%d ",teams[j].num);
        }
        printf("\n");
    }
    return 0;
}
