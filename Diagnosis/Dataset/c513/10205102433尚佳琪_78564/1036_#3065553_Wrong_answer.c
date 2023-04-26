#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long x,y;
    unsigned long long x1,y1;
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
       a[i].x1=a[i].x>0?a[i].x:-a[i].x;
       a[i].y1=a[i].y>0?a[i].y:-a[i].y;
       a[i].l=a[i].x1+a[i].y1;
   }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long ans1=0,ans2=0,temp=0;
    long long temp1=a[0].y-a[1].y;
        temp1=temp1>0?temp1:-temp1;
    long long temp2=a[0].x-a[1].x;
        temp2=temp2>0?temp2:-temp2;
    ans1=temp1+temp2;
   printf("%llu\n",ans1);
  // printf("%llu %lld\n",a[1].x-a[0].x,a[1]);
   for(int i=0;i<n-1;i++)
   {
        int k;
        long long temp1=a[i].y-a[i+1].y;
            temp1=temp1>0?temp1:-temp1;
        long long temp2=a[i].x-a[i+1].x;
            temp2=temp2>0?temp2:-temp2;
        temp=temp1+temp2;
        if(temp%2==0&&temp!=0)
        {
            ans2=0;
            break;
        }
        if(temp==0)
            continue;/////////////两个相同点，不走路程直接下一步
       unsigned long long temp3=1;
        for(int j=0;j<64;j++)
        {
            temp3=temp3*2;
            if(temp<=(temp3-1))
            {
                ans2=ans2+j+1;
                break;
            }
        }
       //printf("%d ",ans2);
   }
   printf("%llu",ans2);

}
