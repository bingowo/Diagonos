#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t,r,c,n,k,j,l,q,p,q1,p1,temp,x,y;
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       printf("case #%d:\n",i);
       int a[11][11]={0};
       scanf("%d%d%d%d",&r,&c,&n,&k);
       for(j=0;j<n;j++)
       {
           scanf("%d%d",&x,&y);
           a[x][y]=1;
       }
       int ans=0;
       for(j=1;j<=r;j++)
       {
           for(l=1;l<=c;l++)
           {
               for(q=1;q+j-1<=r;k++)
               {
                   for(p=1;p+l-1<=c;p++)
                   {
                       temp=0;
                       for(q1=q;q1<q+j;q1++)
                       {
                           for(p1=p;p1<p+l;p1++)
                           {
                               temp+=a[q1][p1];
                           }
                       }
                       if(temp>=k) ans++;
                   }
               }
           }
       }
       printf("%d\n",ans);
   }
}
