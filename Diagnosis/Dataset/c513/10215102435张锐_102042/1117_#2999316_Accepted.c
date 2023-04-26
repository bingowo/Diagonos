#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int xx;
    long long int yy;
    long long int t;
}dian;
int cmp(const int *a,const void *b)
{
    dian *s1=(dian*)a,*s2=(dian*)b;
    if(s1->t<s2->t) return -1;
    else if(s1->t>s2->t) return 1;
    else if(s1->t==s2->t)
    {
        if(s1->xx<s2->xx) return -1;
        else if(s1->xx>s2->xx) return 1;
        else if(s2->xx==s2->xx)
        {
            if(s1->yy>s2->yy) return 1;
            else return -1;
        }
    }
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    int t;
    scanf("%d",&t);
    dian* p=(dian*)malloc(sizeof(dian)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&p[i].xx,&p[i].yy);
        long long int t1=p[i].xx-x,t2=p[i].yy-y;
        if(t1<0) t1=-t1;
        if(t2<0) t2=-t2;
        if(t1<t2) p[i].t=t2;
        else p[i].t=t1;
    }
    qsort(p,t,sizeof(p[0]),cmp);
    printf("%lld\n",p[0].t);
    printf("%lld %lld\n",p[0].xx,p[0].yy);
    free(p);
    return 0;
}
