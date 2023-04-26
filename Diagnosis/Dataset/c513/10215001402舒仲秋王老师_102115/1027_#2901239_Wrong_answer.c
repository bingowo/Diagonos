#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct data
{
    double len;
    double x;
    double y;
};

int xx(double x,double y)
{
    int t;
    if(x>=0&&y>=0) t=1;
    else if(x>0&&y<0) t=4;
    else if(x<0&&y>0) t=2;
    else if(x<=0&&y<=0) t=3;
    return t;
}

int cmp(const void* a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int line1=xx(d1.x,d1.y),line2=xx(d2.x,d2.y),t;
    if(line1!=line2) t=line1-line2;
    else
    {
        if(d1.x==0) t=-1;
        else if(d2.x==0) t=1;
        else
        {
            t=d1.y/d1.x-d2.y/d1.x;
            if(t==0) t=d2.len-d1.len;
        }
    }
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int n,j;
        struct data polar[100];
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            double mid1,mid2;
            scanf("%lf %lf",&mid1,&mid2);
            polar[j].len=mid1*mid1+mid2*mid2;
            polar[j].x=mid1,polar[j].y=mid2;
        }
        qsort(polar,n,sizeof(polar[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            if(xx(polar[j].x,polar[j].y)==1) printf("(%.4lf,%.4lf)\n",sqrt(polar[j].len),atan(polar[j].y/polar[j].x));
            else if(xx(polar[j].x,polar[j].y)==2) printf("(%.4lf,%.4lf)\n",sqrt(polar[j].len),atan(polar[j].y/polar[j].x)+3.1415926);
            else if(xx(polar[j].x,polar[j].y)==3) printf("(%.4lf,%.4lf)\n",sqrt(polar[j].len),atan(polar[j].y/polar[j].x)+3.1415926);
            else if(xx(polar[j].x,polar[j].y)==4) printf("(%.4lf,%.4lf)\n",sqrt(polar[j].len),atan(polar[j].y/polar[j].x)+3.1415926*2);
        }

    }
}
