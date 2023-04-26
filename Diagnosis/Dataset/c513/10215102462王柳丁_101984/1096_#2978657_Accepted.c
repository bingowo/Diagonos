#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,i;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       int num[101][2];
       int cnt,j,sign=1,k;
       scanf("%d",&cnt);
       for(j=0;j<cnt;j++){scanf("%d %d",&num[j][0],&num[j][1]);}
       for(j=0;j<cnt;j++)
       {
           for(k=j;k<cnt;k++)
           {
               if((num[j][0]==num[k][0])&&(num[j][1]!=num[k][1])&&(sign==1)){printf("Poor dxw!\n");sign=0;break;}
           }
           for(k=0;k<cnt;k++)
           {
               if((num[j][1]==num[k][0])&&(sign==1)){printf("Poor dxw!\n");sign=0;break;}
           }
       }
       if(sign==1){printf("Lucky dxw!\n");}
   }
    return 0;
}
