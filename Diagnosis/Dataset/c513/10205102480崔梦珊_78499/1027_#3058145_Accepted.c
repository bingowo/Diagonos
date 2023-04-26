#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI acos(-1)

struct point
{
    double x;
    double y;
    double r;
    double t;
};

int cmp(const void* a,const void* b)
{
    struct point* x=(struct point*)a;
    struct point* y=(struct point*)b;
    if(x->t==y->t)
    {
        if(x->r>y->r)
        {
            return -1;
        }
        return 1;
    }
    if(x->t>y->t)
    {
        return 1;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct point ans[1005];
        for(int k=0;k<N;k++)
        {
            scanf("%lf %lf",&ans[k].x,&ans[k].y);
            double temp=pow(ans[k].x,2)+pow(ans[k].y,2);
            ans[k].r=pow(temp,0.5);

            if(ans[k].x>=0&&ans[k].y>=0)  ans[k].t=atan(ans[k].y/ans[k].x);
            if(ans[k].x>=0&&ans[k].y<0)  ans[k].t=atan(ans[k].y/ans[k].x)+2*PI;
            if(ans[k].x<0)  ans[k].t=atan(ans[k].y/ans[k].x)+PI;


        }
        qsort(ans,N,sizeof(ans[0]),cmp);

        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("(%.4lf,%.4lf)\n",ans[j].r,ans[j].t);
        }
    }
}
