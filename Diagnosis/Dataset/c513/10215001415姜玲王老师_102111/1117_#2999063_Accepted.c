#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct{long long x;long long y;} point;
point p0;
long long number(long long n,long long m)
{
    long long a;
    long long b;
    a=llabs(n-p0.x);
    b=llabs(m-p0.y);
    if(b>a) a=b;
    return a;
}
int main()
{
    point px,p;
    scanf("%lld%lld",&p0.x,&p0.y);
    int n;
    scanf("%d",&n);
    long long min=0,temp;
    scanf("%lld%lld",&p.x,&p.y);
    min=number(p.x,p.y);
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&px.x,&px.y);
        temp=number(px.x,px.y);
        if(temp<min){min=temp;p.x=px.x;p.y=px.y;}
        if(temp==min){if(px.x<p.x){p.x=px.x;p.y=px.y;}
                      if(px.x==p.x&&px.y<p.y){p.x=px.x;p.y=px.y;}}

    }
    printf("%lld\n",min);
    printf("%lld %lld",p.x,p.y);


}
