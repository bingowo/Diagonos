#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   int T,i;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       int num[5][5];
       int j,k;
       for(j=0;j<5;j++){for(k=0;k<5;k++)num[j][k]=1;}
       int oper[3][3];
       for(j=0;j<3;j++){for(k=0;k<3;k++){scanf("%d",&oper[j][k]);}}
       for(j=0;j<3;j++){for(k=0;k<3;k++){oper[j][k]=oper[j][k]%2;}}
       for(j=1;j<4;j++)
       {
           for(k=1;k<4;k++)
           {
               if(oper[j-1][k-1]==1)
               {
                   num[j][k]=(num[j][k]+1)%2;
                   num[j+1][k]=(num[j+1][k]+1)%2;
                   num[j][k+1]=(num[j][k+1]+1)%2;
                   num[j-1][k]=(num[j-1][k]+1)%2;
                   num[j][k-1]=(num[j][k-1]+1)%2;
               }
           }
       }
       printf("case #%d:\n",i);
       for(j=1;j<4;j++)
       {
           for(k=1;k<3;k++){printf("%d ",num[j][k]);}
           printf("%d",num[j][k]);
           if(j!=3)printf("\n");
       }
   }
    return 0;
}
