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
    long long int x1=p[0].x,y1=p[0].y;long long int min=0;
    if(x1>x) min=x1-x;
    else min=x-x1;
    if(y1>y&&(y1-y)>min) min=y1-y;
    else if(y>y1&&(y-y1)>min) min=y-y1;
    for(int i=1;i<t;i++)
    {
        long long int x2=p[i].x,y2=p[i].y;
        long long int temp=0;
        if(x2>x) temp=x1-x;
        else temp=x-x2;
        if(y2>y&&(y2-y)>temp) temp=y2-y;
        else if(y>y2&&(y-y2)>temp) temp=y-y2;
        if(temp<min)
        {
            if(x2<x1||(x2==x1&&y2<y1))
                {min=temp;x1=x2,y1=y2;}
        }
    }
    printf("%lld\n",min);
    printf("%lld %lld\n",x1,y1);
    return 0;
}
