#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct
{
    long long x;long long y;unsigned long long k;
}point;
unsigned long long jue(long long a)
{
    unsigned long long j;
    if(a>=0)j=a;
    else  j=-a;
    return j;
}
unsigned long long zj(point p1,point p2)
{
    unsigned long long re;
    re=jue(p1.x-p2.x)+jue(p1.y-p2.y);
    return re;
}
int cmp(const void*a,const void*b)
{
    point*s1,*s2;
    s1=(point*)a;s2=(point*)b;
    if(s1->k>s2->k)return -1;
    else if(s1->k<s2->k)return 1;
    else
    {
        if(s1->x!=s2->x){if(s1->x>s2->x)return 1;else return -1;}
        else{if(s1->y>s2->y)return 1;else return -1;}
    }
}
unsigned long long  zou(point p1,point p2)
{
   unsigned long long k1=zj(p1,p2);
   unsigned long long l1=1,l2=1,i=1;
   if(k1==0)return 0;
   else
   {
       while(l2<k1)
       {
           l1=l1*2;l2=l2+l1;
           i++;
       }
       return i;
   }
}
int main()
{
    int n,i=0,m=0;
    unsigned long long chang=0;
    point p[110];
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%lld %lld",&p[i].x,&p[i].y);p[i].k=jue(p[i].x)+jue(p[i].y);}
    qsort(p,n,sizeof(p[0]),cmp);
     chang=zj(p[0],p[1]);
     printf("%llu\n",chang);
      for(i=0;i<n-1;i++)
    {
        int k=zou(p[i],p[i+1]);
        if(zj(p[i],p[i+1])==0)continue;
        else if(zj(p[i],p[i+1])%2==0)break;
        else m=m+k;
    }
    printf("%d\n",m);
    return 0;
}
