#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct
{
    long long x;long long y;
}point;
long long jue(long long a)
{
    if(a>=0)return a;
    else return -a;
}
int cmp(const void*a,const void*b)
{
    point*s1,*s2;long long k1,k2;
    s1=(point*)a;s2=(point*)b;
    k1=jue(s1->x)+jue(s1->y);k2=jue(s2->x)+jue(s2->y);
    if(k1>k2)return -1;
    else if(k1<k2)return 1;
    else
    {
        if(s1->x!=s2->x){if(s1->x>s2->x)return 1;else return -1;}
        else{if(s1->y>s2->y)return 1;else return -1;}
    }
}
int zou(point p1,point p2)
{
    int i=0;
   long long k1=jue(p1.x-p2.x)+jue(p1.y-p2.y);long long l1=0,l2=0;
    if(k1%2==0)return 0;
    else
    {
        k1=k1+1;
        for(i=0;;i++)
        {   l1=pow(2,i);l2=l1*2;
            if(k1>l1 && k1<=l2)return i+1;
        }
    }
}
int main()
{
    int n,i=0,m=0;
    long long chang=0;
    point p[110];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld %lld",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(p[0]),cmp);
     chang=jue(p[0].x-p[1].x)+jue(p[0].y-p[1].y);
     printf("%lld\n",chang);
      for(i=0;i<n-1;i++)
    {
        int k=zou(p[i],p[i+1]);
        if(k==0){m=0;break;}
        else m=m+k;
    }
    printf("%d\n",m);
    return 0;
}