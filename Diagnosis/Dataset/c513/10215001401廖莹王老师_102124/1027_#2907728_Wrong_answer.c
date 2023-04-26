#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct
{
    double x;
    double y;
    double jiao;
    double q;
}point;
double js(double x,double y)
{
    double jiao;
   jiao=atan(y/x);
    return jiao;
}
int cmp(const void*a,const void*b)
{
    point *s1,*s2;
    s1=(point*)a;
    s2=(point*)b;
    if(s1->jiao>s2->jiao)return 1;
    else if(s1->jiao<s2->jiao)return -1;
    else
    {
        if(s1->q>s2->q)return -1;
        else return 1;
    }
}
void paixu(h)
{
    int n,i;
    point p[1200];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%lf",&p[i].x);scanf("%lf",&p[i].y);p[i].jiao=js(p[i].x,p[i].y);p[i].q=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);}
    qsort(p,n,sizeof(p[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<n;i++)
    {
        printf("(%.4lf,%.4lf)\n",p[i].q,p[i].jiao);

    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        paixu(h);
    return 0;
}
