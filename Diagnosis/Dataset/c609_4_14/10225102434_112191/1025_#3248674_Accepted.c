#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int num;
    int sum;
    int win;
    int loose;
}Group;
int cmp(const void*a,const void*b)
{
    Group *p1 = (Group*)a;
    Group *p2 = (Group*)b;
    if(p1->sum != p2->sum)return p2->sum-p1->sum;
    else if(p1->sum == p2->sum)
    {
        if(p1->win != p2->win)return p2->win-p1->win;
        else
        {
            if(p1->loose != p2->loose)return p1->loose-p2->loose;
            else if(p1->loose ==p2->loose) return p1->num-p2->num;
        }
    }
}
int main()
{
    int n,m,i,x,y,p;
while(scanf("%d%d",&n,&m))
{
    if(n!=0)
  {
    Group group[n] ;
    for(i = 0;i<n;i++)
    {
        group[i].sum = 0;
        group[i].win = 0;
        group[i].loose = 0;
    }
    for(i = 0;i<m;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&p);
        if(p == 1)
        {
            group[x-1].sum +=3;group[x-1].win++;
            group[y-1].sum -=1;group[y-1].loose++;
        }
        else if(p ==-1)
        {
            group[x-1].sum -=1;group[x-1].loose++;
            group[y-1].sum +=3;group[y-1].win++;
        }
        else
        {
            group[x-1].sum +=1;
            group[y-1].sum +=1;
        }
    }
        for(i = 0;i<n;i++)
            group[i].num = i+1;
        qsort(group,n,sizeof(group[0]),cmp);
        for(i = 0;i<n;i++)printf("%d ",group[i].num);
        printf("%c",'\n');
  }
  else break;
}
    return 0;
}


