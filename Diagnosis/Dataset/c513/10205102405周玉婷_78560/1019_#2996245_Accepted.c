#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int scr;
    int win;
    int lose;
    int num;
} team;

void creat(team t)
{
    t.lose=0;
    t.scr=0;
    t.win=0;
}

int cmp(const void *a,const void *b)
{
    team pa=*(team*) a;
    team pb=*(team*) b;
    if(pa.scr==pb.scr)
    {
        if(pa.win==pb.win) 
        {
            if(pa.lose==pb.lose) return pa.num-pb.num;
            else return pa.lose-pb.lose;
        }
        else return pb.win-pa.win;
    }
    else return pb.scr-pa.scr;
}

int main()
{
    int n,m;
    int a,b,c;
    while(!(n==0&&m==0))
    {
    scanf("%d %d",&n,&m);
    team *p=(team *)malloc(sizeof(team)*(n+1));
    for(int i=1; i<n+1; i++)//初始化
    {
        creat(p[i]);
        p[i].num=i;
    }
    
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        switch ( c )
        {
        case 1:
            p[a].win+=1;
            p[a].scr+=3;
            p[b].lose+=1;
            p[b].scr-=1;
            break;
        case -1:
            p[b].win+=1;
            p[b].scr+=3;
            p[a].lose+=1;
            p[a].scr-=1;   
            break;    
        case 0:
            p[a].scr+=1;
            p[b].scr+=1;
            break;
        }
    }
    qsort(p+1,n,sizeof(team),cmp);

    for(int i=1; i<n+1; i++)
    {
        printf("%d%c",p[i].num,i==n?'\n':' ');
    }
    }
    return 0;
}