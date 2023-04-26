#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    long long x;
    long long y;
    unsigned long long d;//与原点的曼哈顿距离
}P;
int cmp(const void *_a,const void *_b)
{
    P a = *((P*)_a);
    P b = *((P*)_b);
    if(a.d != b.d) return b.d - a.d;
    else
    {
        if(a.x != b.x) return a.x - b.x;
        else return a.y - b.y;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    P p[104];
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].d = abs(p[i].x) + abs(p[i].y);
    }

    qsort(p,n,sizeof(p[0]),cmp);

    printf("%u\n",abs(p[0].x - p[1].x) + abs(p[0].y - p[1].y));//输出排序后的第1个点和第2点之间的曼哈顿距离

    int a = 0;//a为总步数
    for(int i = 0; i < n-1; i++)
    {
        long long x = p[i].x, y = p[i].y;
        unsigned long long dx = abs(p[i+1].x - x), dy = abs(p[i+1].y - y);
        while(1)
        {
            if(dx == 0 && dy == 0) break;
            if(dx+dy == 1)
            {
                a++;
                break;
            }
            if(dx%2 == dy%2)
            {
                printf("%d\n",a);
                return 0;
            }
            a++;
            if(dx%2) dx^=dy^=dx^=dy;
            dx/=2;
            unsigned long long t1 = (dy-1)/2;
            unsigned long long t2 = (dy+1)/2;
            if(dx%2 == t1%2) dy = t2;
            else dy = t1;
        }
    }
    printf("%d\n",a);
    return 0;
}

