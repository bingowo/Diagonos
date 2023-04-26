#include <stdio.h>
#include <stdlib.h>

struct team
{
    int val;
    int sum; //每一队的得分
    int win;
    int lose;
};
int cmp(const void*a,const void*b)
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
            else return -1;
        }
    }

}
int main()
{
    int n,m;
    struct team p[11]={};
    for(int i=0;i<10;i++) p[i].val+=i+1;
    while(scanf("%d ",&n)!=0 && scanf("%d",&m)!=0 )
    {
        for (int i=0;i<m;i++)
        {
            int a,b,c;//a,b为编号
            scanf("%d ;%d %d",&a,&b,&c);
            if(c==1)
            {
                p[a-1].sum+=3;
                p[b-1].sum-=1;
                p[a-1].win+=1;
                p[b-1].lose+=1;
            }
            else if(c==-1)
            {
                p[b-1].sum+=3;
                p[a-1].sum-=1;
                p[b-1].win+=1;
                p[a-1].lose+=1;
            }
            else if (c==0)
            {
                p[a-1].sum+=1;
                p[b-1].sum-=1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int i=0;i<n-1;i++) printf("%d ",p[i].val);
        printf("%d\n",p[n].val);
    }
    return 0;
}
