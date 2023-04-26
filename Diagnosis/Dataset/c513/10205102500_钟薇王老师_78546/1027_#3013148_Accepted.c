#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define  M_PI  3.14159265358979323846  //math.h中的宏定义
struct point
{
    double x,y;
    double p,angle;
};
int cmp(const void *a,const void *b)
{
    struct point p1,p2;
    p1=*(struct point *)a;
    p2=*(struct point *)b;
    if(p1.angle>p2.angle) return 1;  //按极角从小到大排序
    else
        if(fabs(p1.angle-p2.angle)<1e-10)  //判断double类型是否相等
        {
            if(p2.p>p1.p) return 1;
        }
        //极角相同，按极径从大到小排序
    return -1;
}
int main()
{
    int l,T;
    scanf("%d",&T);
    for(l=0;l<T;l++)
    {
        int n; scanf("%d",&n);
        struct point s[1000];
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&s[i].x,&s[i].y);
            s[i].p=sqrt(s[i].x*s[i].x+s[i].y*s[i].y);
            double t=atan2(s[i].y,s[i].x);
            if(t<0) s[i].angle=2*M_PI+t;
            else s[i].angle=t;
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",l);
        for(int i=0;i<n;i++)
            printf("(%.4f,%.4f)\n",s[i].p,s[i].angle);
    }
    return 0;
}
