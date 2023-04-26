#include <stdio.h>
#include <stdlib.h>
long long int x,y;
typedef struct{
    long long int x;
    long long int y;
}dian;
int cmp(const int *a,const void *b)
{
    dian *s1=(dian*)a,*s2=(dian*)b;
    long long int x1=s1->x,y1=s2->y,x2=s2->x,y2=s2->y;
    long long int t1=x1-x,t2=y1-y,t3=x2-x,t4=y2-y;
    if(t1<0) t1=-t1;
    if(t2<0) t2=-t2;
    if(t3<0) t3=-t3;
    if(t4<0) t4=-t4;
    long long int min1,min2;
    if(t1<t2) min1=t2;
    else min1=t1;
    if(t3<t4) min2=t4;
    else min2=t3;
    if(min1<min2) return -1;
    else if(min1>min2) return 1;
    else
    {
        if(x1<x2) return -1;
        else if(x1>x2) return 1;
        else if(x1==x2&&y1<y2) return 1;
        else return -1;
    }
}
int main()
{
    scanf("%lld%lld",&x,&y);
    int t;
    scanf("%d",&t);
    dian* p=(dian*)malloc(sizeof(dian)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    qsort(p,t,sizeof(p[0]),cmp);
    long long int x1=p[0].x,y1=p[0].y;long long int min=x1-x;
    if(min<0) min=-min;
    long long int tt=y1-y;
    if(tt<0) tt=-tt;
    if(tt>min) min=tt;
    printf("%lld\n",min);
    printf("%lld %lld\n",p[0].x,p[0].y);
    free(p);
    return 0;
}
