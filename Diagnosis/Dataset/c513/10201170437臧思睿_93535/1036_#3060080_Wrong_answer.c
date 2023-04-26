#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int llu;
typedef long long int ll;
typedef struct
{
    ll x;
    ll y;
    llu dis;
}P;

ll llab(ll a)
{
    return(a>0)?a:-a;
}

int cmp(const void *a,const void *b)
{
    P *pa=(P *)a;
    P *pb=(P *)b;
    if((pa->dis)!=(pb->dis))
    {
        return ((pa->dis)>(pb->dis))?-1:1;
    }
    else if((pa->x)!=(pb->x)){return ((pa->x)>(pb->x))?1:-1;}
    else{return ((pa->y)>(pb->y))?1:-1;}
}

int main()
{
    int step=0,i=0,n;
    scanf("%d",&n);
    P p[n];
    llu temp;
    while(i++<n)
    {
        scanf("%lld %lld",&p[i-1].x,&p[i-1].y);
        p[i-1].dis=llab(p[i-1].x)+llab(p[i-1].y);
    }
    qsort(p,n,sizeof(P),cmp);
    printf("%llu\n",llab(p[1].x-p[0].x)+llab(p[1].y-p[0].y));
    for(i=1;i<n;i++)
    {
        temp=llab(p[i].x-p[i-1].x)+llab(p[i].y-p[i-1].y);
        if(temp%2==0&&temp!=0){break;}
        else
        {
            while(temp)
            {
                step++;
                temp>>=1;
            }
        }
    }
    printf("%d",step);
    return 0;
}
