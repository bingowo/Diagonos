#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001
struct distant{
    long long int x;
    long long int y;
    long long int dis;
};
struct distant d[MAX];

int cmp(const void *a,const void *b)
{
    struct distant *a1=(struct distant*)a,*b1=(struct distant*)b;
    if(a1->dis>b1->dis)
        return 1;
    else if(a1->dis<b1->dis)
        return -1;
    else
    {
        if(a1->x != b1->x)
        {
            if(a1->x > b1->x)
                return 1;
            else return -1;
        }
        else
        {
            if(a1->y>b1->y)
                return 1;
            else return -1;
        }
    }
}

int main() {
    long long int x0,y0;
    scanf("%d%d",&x0,&y0);
    int n;
    scanf("%d",&n);
    long long a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&a,&b);
        d[i].x=a;
        d[i].y=b;
        a-=x0;
        b-=y0;
        a=a<0?-a:a;
        b=b<0?-b:b;
        d[i].dis=(a>b)?a:b;
    }
    qsort(d,n,sizeof (d[0]),cmp);
    printf("%lld\n%lld %lld\n",d[0].dis,d[0].x,d[0].y);
    return 0;
}
