#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int x,y;
    int l;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.l!=s2.l)
        return s2.l-s1.l;
    else
    {
        if(s1.x!=s2.x)
            return s1.x-s2.x;
        else
            return s1.y-s2.y;
    }
}

int main()
{
   int n;
   scanf("%d",&n);
   node a[n];
   for(int i=0;i<n;i++)
   {
       scanf("%d %d",&a[i].x,&a[i].y);
       a[i].l=abs(a[i].x)+abs(a[i].y);
   }
   qsort(a,n,sizeof(a[0]),cmp);
   int ans1=0,ans2=0;
   ans1=abs(a[0].x-a[1].x)+abs(a[0].y-a[1].y);
   printf("%d\n",ans1);
   for(int i=0;i<n-1;i++)
   {
       int k;
       ans1=abs(a[i].x-a[i+1].x)+abs(a[i].y-a[i+1].y);
       for(k=1;k<64;k++)
       {
           if(ans1<=(pow(2,k)-1))break;
       }
       int temp=pow(2,k)-1-ans1;
       if(temp%2==1)
       {
           ans2=0;
           break;
       }
       else
            ans2+=k;
       //printf("%d ",ans2);
   }
   printf("%d",ans2);

}
