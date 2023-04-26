#include <stdio.h>
#include <stdlib.h>

struct team
{
    int val;
    int sum; //每一队的得分
    int win;
    int lose;
}p[15];

int cmp(const void *a,const void *b)
{
    struct team d1,d2;
    d1=*((struct team *)a);
    d2=*((struct team *)b);
    if(d2.sum!=d1.sum) return d2.sum-d1.sum;
    else
    {
        if(d2.win!=d1.win) return d2.win-d1.win;
        else
        {
            if(d2.lose!=d1.lose) return d1.lose-d2.lose;
            else return d1.val-d2.val;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF && n!=0 || m!=0)
    {
        for(int i=1;i<=n;i++)
        {
            p[i].sum=0;
            p[i].val=i;
            p[i].win=0;
            p[i].lose=0;
        }
        for (int i=0;i<m;i++)
        {
            int a,b,c;//a,b为编号
            scanf("%d %d %d",&a,&b,&c);
            switch(c)
            {
                case 1:
                    p[a].sum+=3;
                    p[b].sum-=1;
                    p[a].win+=1;
                    p[b].lose+=1;
                    break;
                case -1:
                    p[b].sum+=3;
                    p[a].sum-=1;
                    p[b].win+=1;
                    p[a].lose+=1;
                    break;
                case 0:
                    p[a].sum+=1;
                    p[b].sum+=1;
                    break;
            }
        }
        qsort(p+1,n,sizeof(p[1]),cmp);
        int j;
        for(j=1;j<n;j++) printf("%d ",p[j].val);
        printf("%d\n",p[j].val);
    }
    return 0;
}
