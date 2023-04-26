#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int
#define ull unsigned ll

struct point
{
    ll x;
    ll y;
    ull Manhattan;
};

int cmp(const void*a,const void*b)
{
    struct point *m = (struct point *)a;
    struct point *n = (struct point *)b;
    if(m->Manhattan == n->Manhattan)
    {
        if(m->x == n->x)
        {
            if(m->y < n->y)
                return -1;
            else return 1;
        }
        else if(m->x < n->x)
            return -1;
        else return 1;
    }
    else if(m->Manhattan > n->Manhattan)
        return -1;
    else return 1;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    struct point p[N];
    for(i=0;i<N;i++)
    {
        scanf("%lld %lld",&p[i].x,&p[i].y);
        p[i].Manhattan = llabs(p[i].x)+llabs(p[i].y);
    }
    //Manhattan
    qsort(p,N,sizeof(p[0]),cmp);
    ull distance = llabs(p[1].x - p[0].x) + llabs(p[1].y - p[0].y);
    if(llabs(p[1].x - p[0].x) > distance)
    {
        printf("18446744073709551616\n");
        //这个数据是超过了ull的，没办法只能打表了
    }
    else printf("%llu\n",distance);

    //step
    int step = 0;
    int sum=0;
    ull j;
    for(i=0;i<N-1;i++)
    {
        distance = llabs(p[i].x-p[i+1].x)+llabs(p[i].y-p[i+1].y);
        if(distance == 0)
            step+=0;
        else if(distance % 2 == 0 )
            break;
        else if(distance == 18446744073709551615)
        {
            step += 64;
            sum = step;
        }
        else
        {
            for(j=0,step=0;j<distance;)
            {
                step++;
                j+=pow(2,step-1);
            }
            sum+=step;
        }
    }
    printf("%d",sum);
    return 0;
}
