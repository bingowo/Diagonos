#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;//编号
    int sco;//分数
    int win;//胜场
    int lose;//负场
}team;

int cmp(const void *a,const void *b)
{
    team c=*(team*)a;
    team d=*(team*)b;
    if(c.sco!=d.sco)
        return d.sco-c.sco;
    else
    {
        if(c.win!=d.win)
            return d.win-c.win;
        else
        {
            if(c.lose!=d.lose)
                return c.lose-d.lose;
            else return c.cnt-d.cnt;
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d",&n)!=0&&scanf("%d",&m)!=0)
    {
        team t[10];
        for(int i=0;i<n;i++)
        {
            t[i].cnt=i+1;
            t[i].sco=0;
            t[i].win=0;
            t[i].lose=0;
        }
        int s[m][3];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&s[i][j]);
            }
            int a=s[i][0];
            int b=s[i][1];
            if(s[i][2]==1)
            {
                t[a-1].sco+=3;
                t[b-1].sco-=1;
                t[a-1].win+=1;
                t[b-1].lose+=1;
            }
            else if(s[i][2]==-1)
            {
                t[b-1].sco+=3;
                t[a-1].sco-=1;
                t[b-1].win+=1;
                t[a-1].lose+=1;
            }
            else
            {
                t[a-1].sco+=1;
                t[b-1].sco+=1;
            }
        }
        qsort(t,n,sizeof(t),cmp);
        for(int i=0;i<n-1;i++)
            printf("%d ",t[i].cnt);
        printf("%d\n",t[n-1].cnt);
    }
    return 0;
}
