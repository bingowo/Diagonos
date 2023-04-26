#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int name,sco,win,los;
}player;
int cmp(const void* a,const void* b)
{
    player c=*(player*)a,d=*(player*)b;
    if(c.sco!=d.sco) return d.sco-c.sco;
    if(c.win!=d.win) return d.win-c.win;
    if(c.los!=d.los) return c.los-d.los;
    return c.name-d.name;
}
int main()
{
    int a,m,n,i,j,c;
    player *playe;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(m!=0 && n!=0)
        {
            playe=(player*)malloc(n*sizeof(player));
            for(a=0;a<n;a++)
            {
                playe[a].name=a+1;
                playe[a].sco=0;
                playe[a].win=0;
                playe[a].los=0;
            }
            for(a=0;a<m;a++)
            {
                scanf("%d %d %d",&i,&j,&c);
                if(c==1)
                {
                    playe[i-1].sco=playe[i-1].sco+3;
                    playe[j-1].sco=playe[j-1].sco-1;
                    playe[i-1].win++;
                    playe[j-1].los++;
                }
                else if(c==0)
                {
                    playe[i-1].sco++;
                    playe[j-1].sco++;
                }
                else
                {
                    playe[i-1].sco=playe[i-1].sco-1;
                    playe[j-1].sco=playe[j-1].sco+3;
                    playe[i-1].los++;
                    playe[j-1].win++;
                }
            }
            qsort(playe,n,sizeof(playe[0]),cmp);
            for(a=0;a<n;a++)
            {
                printf("%d",playe[a].name);
            }
        }
    }
    return 0;
}
