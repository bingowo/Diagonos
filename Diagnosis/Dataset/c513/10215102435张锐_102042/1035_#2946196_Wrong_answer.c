#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;//半径
    int y;//高
    int s1;//侧面积
    int s2;//底面积
}q;
int cmp(const void *a,const void *b)
{
    q *q1=(q*)a,*q2=(q*)b;
    if(q1->s1>q2->s1) return 0;
    else if(q1->s1<q2->s1) return 1;
    else if(q1->s1==q2->s1)
    {
        if(q1->s2<q2->s2) return 1;
        else return 0;
    }
    else return 1;
}
int main()
{
    int t,n;
    scanf("%d%d",&t,&n);
    q *p=(q *)malloc(t*sizeof(q));
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].s1=(int)(2*p[i].x*p[i].y);
        p[i].s2=(int)(p[i].x*p[i].x);
    }
    qsort(p,t,sizeof(p[0]),cmp);int all=0;
    if(n==1) printf("%d",p[0].s1+p[0].s2);
    else
    {
        all+=p[0].s1;int num=1,temp=p[0].s2;int i;
        for(i=1;num<n;i++)
        {
            if(p[i].s2<=temp) {all+=p[i].s2-temp+p[i].s1;temp=p[i].s2;num++;}
        }
        all+=p[i-1].s2;
        printf("%d\n",all);
    }
    free(p);
    return 0;
}
