#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
struct jji
{
    double ch;
    double hu;
};
int cmp(const void *a,const void *b)
{
    struct jji *p1,*p2;
    p1=(struct jji *)a;
    p2=(struct jji *)b;
    if(p1->hu>p2->hu)
        return 1;
    else if(fabs(p1->hu-p2->hu)<1e-8)
            if(p1->ch<p2->ch)
               return 1;
    return -1;
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,i;
        scanf("%d",&n);
        struct jji ji[n+1];
        for(i=0;i<n;i++)
        {
            double x,y,z;
            double flag=0;
            scanf("%lf%lf",&x,&y);
            ji[i].ch=sqrt(x*x+y*y);
            if(x<0&&y>0)
            {
                x=-x;
                flag=1;
            }
            else if(x<0&&y<0)
            {
                x=-x;
                y=-y;
                flag=2;
            }
            else if(x>0&&y<0)
            {
                y=-y;
                flag=3;
            }
            else if(x<0&&y==0)
            {
                x=-x;
                flag=2;
            }
            else if(x==0&&y<0)
            {
                y=-y;
                flag=2;
            }
            z=y/x;
            z=atan(z);
            z+=PI*(flag/2);
            ji[i].hu=z;
        }
        qsort(ji,n,sizeof(ji[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("(%.4lf,%.4lf)\n",ji[i].ch,ji[i].hu);
        }
    }
    return 0;
}
