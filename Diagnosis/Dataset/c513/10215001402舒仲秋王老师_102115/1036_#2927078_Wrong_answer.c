#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct data
{
    long long int x;
    long long int y;
};

int cmp(const void* a,const void* b)
{
    struct data d1,d2;
    int t,f,g,h,j;
    d1=*((struct data*)a),d2=*((struct data*)b);
    f=d1.x,g=d2.x,h=d1.y,j=d2.y;
    if(d1.x<0) f=-d1.x;
    if(d2.x<0) g=-d2.x;
    if(d1.y<0) h=-d1.y;
    if(d2.y<0) j=-d2.y;
    if((f+h)>(g+j)) t=-1;
    else if((f+h)<(g+j)) t=1;
    else
    {
        if(d1.x>d2.x) t=1;
        else if(d1.x<d2.x) t=-1;
        else
        {
            if(d1.y>d2.y) t=1;
            else t=-1;
        }
    }
    return t;
};

long long int lenth(struct data d1,struct data d2)
{
    long long int t,q;
    if(d1.x>d2.x) t=d1.x-d2.x;
    else t=d2.x-d1.x;
    if(d1.y>d2.y) q=d1.y-d2.y;
    else q=d2.y-d1.y;
    return t+q;
}

int main()
{
    int n,i,j,flag=0;
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
                mid=t-pow(2,j);
                if(mid<=0) break;
            }
            flag+=j;
        }
    }
    printf("%d",flag);
    return 0;
}
