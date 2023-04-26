#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    double a;
    double b;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* p=(sss*)_a;
    sss* q=(sss*)_b;
    if((p->b)!=(q->b)) return ((p->b)>(q->b)?1:-1);
    else return ((p->a)>(q->a)?-1:1);
}
int main()
{
    int T;
    scanf("%d",&T);
    int n;double x,y;
    sss s[1010];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lf %lf",&x,&y);
            s[j].a=sqrt(x*x+y*y);
            if(x>0 && y>0) s[j].b=atan(y/x);
            else if(x>0 && y<0) s[j].b=atan(y/x)+2*3.1415926;
            else if(x<0 && y<0) s[j].b=atan(y/x)+3.1415926;
            else if(x<0 && y>0) s[j].b=atan(y/x)+3.1415926;
            else if(x==0 && y==0) s[j].b=0;
            else if(x==0 && y>0) s[j].b=3.1415926/2;
            else if(x==0 && y<0) s[j].b=3.1415926*3/2;
            else if(y==0 && x>0) s[j].b=0;
            else if(y==0 && x<0) s[j].b=3.1415926;
        }
        qsort(s,n,sizeof(sss),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
             printf("(%.4lf,%.4lf)\n",s[j].a,s[j].b);
        }
    }
    return 0;
}
