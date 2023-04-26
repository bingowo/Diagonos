#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct data
{
    double len;
    double tan;

};

int cmp(const void* a,const void *b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    if(d1.tan<d2.tan) t=-1;
    else if(d1.tan>d2.tan) t=1;
    else
    {
        if(d2.len>d1.len) t=1;
        else t=-1;
    }
    return t;
}

int xx(double x,double y)
{
    int t;
    if(x>=0&&y>=0) t=1;
    else if(x>0&&y<0) t=4;
    else if(x<0&&y>=0) t=2;
    else if(x<=0&&y<0) t=3;
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int n,j;
        struct data polar[5000];
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            double mid1,mid2;
            scanf("%lf %lf",&mid1,&mid2);
            polar[j].len=sqrt(mid1*mid1+mid2*mid2);
            if(xx(mid1,mid2)==3) polar[j].tan=atan2(mid2,mid1)+2*3.1415926;
            else if(xx(mid1,mid2)==4) polar[j].tan=atan2(mid2,mid1)+2*3.1415926;
            else polar[j].tan=atan2(mid2,mid1);
        }
        qsort(polar,n,sizeof(polar[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("(%.4lf,%.4lf)\n",polar[j].len,polar[j].tan);
    }
    return 0;
}
