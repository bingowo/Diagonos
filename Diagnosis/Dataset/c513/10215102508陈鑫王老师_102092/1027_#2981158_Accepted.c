#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926
struct zhi
{
    double x;
    double y;
};
struct ji
{
    double a;
    double b;
};
int cmp(const void*a,const void*b)
{
    struct ji x=*(struct ji*)a;
    struct ji y=*(struct ji*)b;
    if(x.b!=y.b) return x.b<y.b?-1:1;
    else return x.a>y.a?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct zhi temp[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lf %lf",&temp[j].x,&temp[j].y);
        }
        struct ji ans[N];
        for(int j=0;j<N;j++)
        {
            ans[j].a=sqrt(temp[j].x*temp[j].x+temp[j].y*temp[j].y);
            if(temp[j].x==0&&temp[j].y==0) ans[j].b=0;
            else if(temp[j].x==0&&temp[j].y>0) ans[j].b=pi/2;
            else if(temp[j].x==0&&temp[j].y<0) ans[j].b=pi*3/2;
            else if(temp[j].x<0) ans[j].b=(atan(temp[j].y/temp[j].x)+pi);
            else if(temp[j].x>0&&temp[j].y<0) ans[j].b=(atan(temp[j].y/temp[j].x)+2*pi);
            else ans[j].b=atan(temp[j].y/temp[j].x);
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("(%.4f,%.4f)\n",ans[j].a,ans[j].b);
        }

    }
    return 0;
}
