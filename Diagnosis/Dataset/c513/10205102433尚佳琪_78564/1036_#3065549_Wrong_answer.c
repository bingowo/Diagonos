#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long x,y;
    unsigned long long l;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.l!=s2.l)
    {
        if(s1.l>s2.l)
            return -1;
        else
            return 1;
    }
    else
    {
        if(s1.x!=s2.x)
        {
            if(s1.x>s2.x)
                return 1;
            else return -1;
        }
        else
        {
            if(s1.y>s2.y)
                return 1;
            else
                return -1;
        }

    }
}

int main()
{
   int n;
   scanf("%d",&n);
   node a[n];
   for(int i=0;i<n;i++)
   {
       scanf("%lld %lld",&a[i].x,&a[i].y);
       a[i].l=llabs(a[i].x)+llabs(a[i].y);
       //printf("%llu\n",a[i].l);
   }
   qsort(a,n,sizeof(a[0]),cmp);
   unsigned long long ans1=0,ans2=0;
   ans1=llabs(a[0].x-a[1].x)+llabs(a[0].y-a[1].y);
   printf("%llu\n",ans1);
  // printf("%llu %lld\n",a[1].x-a[0].x,a[1]);
   for(int i=0;i<n-1;i++)
   {
       int k;
       ans1=llabs(a[i].x-a[i+1].x)+llabs(a[i].y-a[i+1].y);
       for(k=1;k<64;k++)
       {
           if(ans1<=(pow(2,k)-1))break;
       }
       unsigned long long temp=pow(2,k)-1-ans1;
       if(temp%2==1)
       {
           ans2=0;
           break;
       }
       else
            ans2+=k;
       //printf("%d ",ans2);
   }
   printf("%llu",ans2);

}
