#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long x;
    long long y;
    long long distance;
}point;

long long jdz(long long n)
{
    long long re;
    if(n>=0) re=n;
    else re=-n;
    return re;
}

int cmp(const void*a,const void*b)
{
    point aa=*((point*)a);
    point bb=*((point*)b);
    if(aa.distance>bb.distance) return -1;
    else if(aa.distance<bb.distance) return 1;
    else
    {
        if(aa.x>bb.x) return 1;
        else if(aa.x<bb.x) return -1;
        else
        {
            if(aa.y>bb.y) return 1;
            else if(aa.y<=bb.y) return -1;
        }
    }
}

long long manhaton(point a,point b)
{
    long long re;
    re=jdz(a.x-b.x)+jdz(a.y-b.y);
    return re;
}

long long nofneed(point a,point b)
{
    long long n=1,dis,zong=1,i=1;
    dis=manhaton(a,b);
    if (dis==0) return 0;
    else
    {
        while(zong<dis)
        {
            n*=2;
            zong+=n;
            i++;
        }
        return i;
    }

}

int main()
{
   int n,i;
   point p[200];
   memset(p,0,sizeof(point)*200);
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%lld%lld",&p[i].x,&p[i].y);
       p[i].distance=jdz(p[i].x)+jdz(p[i].y);
   }
   qsort(p,n,sizeof(point),cmp);
   long long re1,re2,step=0;
   re1=manhaton(p[0],p[1]);
   printf("%lld\n",re1);
   for(i=0;i<n-1;i++)
   {
       if(manhaton(p[i],p[i+1])%2==0) break;
       step+=nofneed(p[i],p[i+1]);
   }
   if(i==0) re2=0;
   else re2=step;
   printf("%lld\n",re2);


}
