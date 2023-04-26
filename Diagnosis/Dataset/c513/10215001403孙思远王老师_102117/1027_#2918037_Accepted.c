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
    if((p1->hu-p2->hu)>1e-7)
        return 1;
    else if((p1->hu-p2->hu)<-1e-7)
        return -1;
    else if((p1->ch-p2->ch)<-1e-7)
        return 1;
    else
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
        struct jji ji[n];
        for(i=0;i<n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            ji[i].ch=sqrt(x*x+y*y);
            ji[i].hu=atan2(y,x);
            if(ji[i].hu<0)
                ji[i].hu+=2*PI;
        }
        qsort(ji,n,sizeof(ji[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("(%.4lf,%.4lf)\n",ji[i].ch,ji[i].hu);
        }
    }
    return 0;
}
