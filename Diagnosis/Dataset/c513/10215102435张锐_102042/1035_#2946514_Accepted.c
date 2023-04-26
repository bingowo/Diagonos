#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int x;//半径
    long long int y;//高
    long long int s1;//侧面积
    long long int s2;//底面积
}q;
int cmp1(const void *a,const void *b)//排侧面积s1
{
    q *q1=(q*)a,*q2=(q*)b;
    if(q1->s1>=q2->s1) return 0;
    else if(q1->s1<q2->s1) return 1;
}
int cmp2(const void *a,const void *b)//排表面积s2
{
    q *q1=(q*)a,*q2=(q*)b;
    if(q1->s2<q2->s2) return 1;
    else return 0;
}
int main()
{
    long long int t,n;
    scanf("%lld%lld",&t,&n);
    q *p=(q *)malloc(t*sizeof(q));
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].s1=(2*p[i].x*p[i].y);
        p[i].s2=(p[i].x*p[i].x);
    }
    qsort(p,t,sizeof(p[0]),cmp1);
    qsort(p,n,sizeof(p[0]),cmp2);
    long long int all1=p[0].s2;
    for(int i=0;i<n;i++)
    {
        all1+=p[i].s1;
    }
    qsort(p,t,sizeof(p[0]),cmp2);
    long long int all2=p[0].s1+p[0].s2;
    qsort(p+1,t,sizeof(p[0]),cmp1);
    for(int i=1;i<n;i++)
    {
        all2+=p[i].s1;
    }
    if(all1>all2) printf("%lld\n",all1);
    else printf("%lld\n",all2);
    free(p);
    return 0;
}
