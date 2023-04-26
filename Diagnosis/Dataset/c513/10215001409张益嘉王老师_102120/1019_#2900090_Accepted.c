#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int name;
    int score;
    int win;
    int lost;
} team;

int cmp(const void*a,const void*b)
{
    team aa=*((team*)a);
    team bb=*((team*)b);
    if((aa.score)>(bb.score)) return -1;
    else if ((aa.score)<(bb.score)) return 1;
    else
    {
        if((aa.win)>(bb.win)) return -1;
        else if ((aa.win)<(bb.win)) return 1;
        else
        {
            if ((aa.lost)<(bb.lost)) return -1;
            else if ((aa.lost)>(bb.lost)) return 1;
            else
            {
                if ((aa.name)<=(bb.name)) return -1;
                else if ((aa.name)>(bb.name)) return 1;
            }
        }

    }

}

/*int cmp2 (const void*a,const void*b)
{
    team aa=*((team*)a);
    team bb=*((team*)b);
    if ((aa.name)<(bb.name)) return -1;
    else if ((aa.name)>(bb.name)) return 1;
}*/

int main()
{
    int i,c,j,a1,b1,m,n,co=0;
    team t[100];

    while(1)
    {


        scanf("%d%d",&n,&m);
        if((n==0)&&(m==0)) break;
        for(i=0;i<n;i++)
        {
                t[i].lost=0;
                t[i].score=0;
                t[i].win=0;
                t[i].name=i+1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a1,&b1,&c);
            t[a1-1].name=a1;
            t[b1-1].name=b1;

            if(c==1)
            {
                t[a1-1].win++;
                t[a1-1].score+=3;
                t[b1-1].lost++;
                t[b1-1].score--;
            }
            else if(c==-1)
            {
                t[a1-1].lost++;
                t[a1-1].score--;
                t[b1-1].win++;
                t[b1-1].score+=3;
            }
            else if(c==0)
            {
                t[a1-1].score++;
                t[b1-1].score++;
            }

        }
        qsort(t,n,sizeof(team),cmp);
        team *p=t;
        for(j=0;j<n-1;j++)
        {
            printf("%d ",p->name);
            p++;
        }
        printf("%d",p->name);
        printf("\n");
        //p=t;
        /*for(j=0;j<n;j++)
        {printf("test [%d]score=%d\n",p->name,p->score);p++;}*/

    }
    return 0;
}
