#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct
{
    int bianhao;
    int sum;
    int win;
    int lose;
    int draw;
} team;
int cmp(const void*a,const void*b)
{
    team *pa=(team*)a;
    team *pb=(team*)b;
    if((pa->sum)==(pb->sum))
    {
        //积分相同
        if((pa->win)==(pb->win))
        {
            //胜场相同
            if(pa->lose==pb->lose)
            {
                return pa->bianhao-pb->bianhao;
            }
            else return pa->lose-pb->lose;
        }
        else return -(pa->win-pb->win);
    }
    else
    {
        return -(pa->sum-pb->sum);
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        team t[n];
        for(int i=1; i<=n; i++)
        {
            t[i-1].bianhao=i;
            t[i-1].draw=0;
            t[i-1].win=0;
            t[i-1].lose=0;
            t[i-1].sum=0;
        }
        while(m!=0)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                t[a-1].win+=1;
                t[a-1].sum+=3;
                t[b-1].lose+=1;
                t[b-1].sum-=1;
            }
            else if (c==-1)
            {
                t[b-1].win+=1;
                t[b-1].sum+=3;
                t[a-1].lose+=1;
                t[a-1].sum-=1;
            }
            else
            {
                t[b-1].draw+=1;
                t[b-1].sum+=1;
                t[a-1].draw+=1;
                t[a-1].sum+=1;
            }
            m--;
        }
        qsort(t,n,sizeof(team),cmp);
        for(int i=0; i<n; i++)
        {
            printf("%d",t[i].bianhao);
            if(i!=n-1)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}