#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int x;
    long long int y;
}dian;

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    int t;
    scanf("%d",&t);
    dian* p=(dian*)malloc(sizeof(dian)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    long long int x1=p[0].x,y1=p[0].y;long long int min=x1-x;
    if(min<0) min=-min;
    long long int tt=y1-y;
    if(tt<0) tt=-tt;
    if(tt>min) min=tt;
    for(int i=1;i<t;i++)
    {
        long long int x2=p[i].x,y2=p[i].y;
        long long int temp=x2-x;
        if(temp<0) temp=-temp;
        tt=y2-y;
        if(tt<0) tt=-tt;
        if(tt>temp) temp=tt;
        if(temp<=min)
        {
            if(x2<x1||(x2==x1&&y2<y1))
                {min=temp;x1=x2,y1=y2;}
        }
    }
    printf("%lld\n",min);
    printf("%lld %lld\n",x1,y1);
    return 0;
}
