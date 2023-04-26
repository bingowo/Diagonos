#include <stdio.h>
#include <string.h>
typedef long long int ll;
typedef struct {int num;int sco;int nz;int nf}Team;

int cmp(const void*pa,const void *pb)
{
    Team *a=(Team *)pa;
    Team *b=(Team *)pb;
    if(a->sco!=b->sco)
        {return (a->sco < b->sco)?1:-1;}
    else if(a->nz!=b->nz)
        {return (a->nz < b->nz)?1:-1;}
    else if(a->nf!=b->nf)
        {return (a->nf < b->nf)?-1:1;}
    else {return (a->num > b->num)?1:-1;}
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    while(n!=0)
    {
        Team t[n];
        for(int i=0;i<n;i++){t[i].sco=0;t[i].nz=0;t[i].nf=0;}
        while(m--)//m为比赛场数
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            a-=1;b-=1;
            if(c==0)
            {
                t[a].sco+=1;
                t[b].sco+=1;
            }
            else if(c==1)
            {
                t[a].sco+=3;
                t[b].sco-=1;
                t[a].nz+=1;
                t[b].nf+=1;
            }
            else
            {
                t[a].sco-=1;
                t[b].sco+=3;
                t[a].nf+=1;
                t[b].nz+=1;
            }
        }
        for(int i=0;i<n;i++){t[i].num=i+1;}
        qsort(t,n,sizeof(Team),cmp);
        for(int i=0;i<n;i++)
        {
            printf("%d ",t[i].num);
        }
        printf("\n");
        scanf("%d %d",&n,&m);
    }
    return 0;
}
