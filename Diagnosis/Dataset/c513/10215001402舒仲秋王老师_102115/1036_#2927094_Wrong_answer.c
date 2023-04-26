#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int x;
    long long int y;
};

long long int lenth(struct data d1,struct data d2)
{
    long long int t,q;
    t=d1.x-d2.x;
    if(t<0) t=-t;
    q=d1.y-d2.y;
    if(q<0) q=-q;
    return t+q;
}

int cmp(const void* a,const void* b)
{
    struct data d1,d2,d3;
    d3.x=0,d3.y=0;
    int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    long long int p=lenth(d1,d3),q=lenth(d2,d3);
    if(p>q) t=-1;
    else t=1;
    return t;
};

int main()
{
    long long int n,i,j,flag=0,q;
    struct data p[200];
    long long int t,mid;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%lld\n",lenth(p[0],p[1]));
    for(i=0;i<n-1;i++)
    {
        long long int t=lenth(p[i],p[i+1]);
        if(t%2==0) break;
        else
        {
            for(j=0;;j++)
            {
                long long int mid0=1;
                    for(q=j;q>0;q--) mid0*=2;
                mid=t-mid0;
                if(mid<=0) break;
            }
            flag+=j;
        }
    }
    printf("%d",flag);
    return 0;
}
