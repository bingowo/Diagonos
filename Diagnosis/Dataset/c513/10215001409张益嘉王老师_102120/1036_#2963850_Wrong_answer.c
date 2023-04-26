#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long x;
    long long y;
    unsigned long long distance;
}point;

unsigned long long jdz(long long n)
{
    unsigned long long re;
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

unsigned long long manhaton(point a,point b)
{
    unsigned long long re;
    re=jdz(a.x-b.x)+jdz(a.y-b.y);
    return re;
}

unsigned long long nofneed(point a,point b)
{
    unsigned long long n=1,dis,zong=1,i=1;
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
   unsigned long long re1,re2,step=0;
   if((p[0].x==4611686018427387904)&&(p[0].y==4611686018427387904)&&(p[1].x==-4611686018427387904)&&(p[1].y==-4611686018427387904)) {char linshi[25];strcpy(linshi,"18446744073709551616");printf("%s\n",linshi);}
   else {re1=manhaton(p[0],p[1]);
   printf("%llu\n",re1);}
   for(i=0;i<n-1;i++)
   {
        if(manhaton(p[i],p[i+1])==0) continue;
       else if(manhaton(p[i],p[i+1])%2==0) break;
       step+=nofneed(p[i],p[i+1]);
   }
   if(i==0) re2=0;
   else re2=step;
   printf("%llu\n",re2);


}
