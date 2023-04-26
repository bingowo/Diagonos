#include <stdio.h>
#include <stdlib.h>

int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       int s1[100];
       int s2[100];
       for(int j=0;j<100;j++) s1[j]=0;
       for(int k=0;k<100;k++) s2[k]=0;
       int x,y;
       scanf("%d %d",&x,&y);
       int a=0,b=0;
       while(x/2)
       {
           s1[a++]=x%2;
           x=x/2;
       }
       s1[a]=x;
       while(y/2)
       {
           s2[b++]=y%2;
           y=y/2;
       }
       s2[b]=y;
       int ans=0;
       for(int q=0;q<100;q++)
       {
           if(s1[q]!=s2[q]) ans++;
       }
       printf("%d\n",ans);
   }
}
