#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
   int a[5][5];
   int T;
   scanf("%d",&T);
   for(int cas=0;cas<T;cas++)
   {
       for(int i=0;i<5;i++)
       {
           for(int j=0;j<5;j++)
           {
               a[i][j]=1;
           }
       }
       int b[5][5];
       for(int i=1;i<=3;i++)
       {
           for(int j=1;j<=3;j++)
           {
               scanf("%d",&b[i][j]);
               int x=b[i][j]%2;
               if(x!=0)
               {
                   a[i][j]=a[i][j]^1;
                   a[i][j-1]=a[i][j-1]^1;
                   a[i][j+1]=a[i][j+1]^1;
                   a[i-1][j]=a[i-1][j]^1;
                   a[i+1][j]=a[i+1][j]^1;
               }
           }
       }
       printf("case #%d:\n",cas);
       for(int i=1;i<=3;i++)
       {
           for(int j=1;j<3;j++)
           {
               printf("%d ",a[i][j]);
           }
           printf("%d\n",a[i][3]);
       }
   }
   return 0;
}
