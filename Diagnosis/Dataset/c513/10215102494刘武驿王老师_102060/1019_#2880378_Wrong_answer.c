#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct res
{
    int num;
    int win;
    int lose;
    int sum;
};
int cmp(void*a,void*b)
{
 if (((struct res *)a)->sum!=((struct res*)b)->sum) return (((struct res*)b)->sum-((struct res*)a)->sum);
    if(((struct res*)b)->win!=((struct res*)a)->win) return  (((struct res*)b)->win-((struct res*)a)->win);
    if(((struct res*)a)->lose!=((struct res*)b)->lose) return (((struct res*)a)->lose-((struct res*)b)->lose);
    return (((struct res*)a)->num-((struct res*)b)->num);
}

int main()
{
    int n,m,res[3];
    struct res group[10];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        group[i].num=i+1;
        group[i].sum=0;
        group[i].win=0;
        group[i].lose=0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&res[0],&res[1],&res[2]);;
        if(res[2]==1)
        {
            group[res[0]-1].sum+=3;
            group[res[1]-1].sum-=1;
            group[res[0]-1].win+=1;
            group[res[1]-1].lose+=1;
        }
        if(res[2]==-1)
        {
            group[res[1]-1].sum+=3;
            group[res[0]-1].sum-=1;
            group[res[1]-1].win+=1;
            group[res[0]-1].lose+=1;
        }
        if(res[2]==0)
        {
            group[res[0]-1].sum+=1;
            group[res[1]-1].sum+=1;
        }
    }
    qsort(group,n,sizeof(struct res),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%d ",group[i].num);
    }
}
