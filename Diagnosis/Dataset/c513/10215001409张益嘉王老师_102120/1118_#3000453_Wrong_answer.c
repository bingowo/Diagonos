#include <stdio.h>
#include <stdlib.h>

int main()
{
     int lie,hang,jiao;
     char xiang;
     scanf("%d%d%d %c",&lie,&hang,&jiao,&xiang);
     //printf("%d %d %d %c",lie,hang,jiao,xiang);
     int i,j,a[210][210];
     for(i=0;i<hang;i++)
     {
         for(j=0;j<lie;j++)
         {
             scanf("%d",&a[i][j]);
         }
     }
     int cir=jiao/90;
     cir%=4;
     int ha,li;
     if(xiang=='L') cir=(4-cir)%4;
     if(cir==0)
     {
         printf("%d %d\n",hang,lie);
         for(i=0;i<hang;i++)
         {
             for(j=0;j<lie;j++)
             {
                 printf("%d",a[i][j]);
                 if(i!=lie-1) printf(" ");
                 else printf("\n");
             }
         }
     }
     else if(cir==1)
     {
         li=hang;
         ha=lie;
         printf("%d %d\n",ha,li);
         for(j=0;j<lie;j++)
         {
             for(i=hang-1;i>=0;i--)
             {
                 printf("%d",a[i][j]);
                 if(i!=0) printf(" ");
                 else printf("\n");
             }
         }
     }

     else if(cir==2)
     {
         printf("%d %d\n",hang,lie);
         for(i=hang-1;i>=0;i--)
         {
             for(j=lie-1;j>=0;j--)
             {
                 printf("%d",a[i][j]);
                 if(j!=0) printf(" ");
                 else printf("\n");
             }
         }
     }
     else if(cir==3)
     {
         printf("%d %d\n",lie,hang);
         for(j=lie-1;j>=0;j--)
         {
             for(i=0;i<hang;i++)
             {
                 printf("%d",a[i][j]);
                 if(i!=hang-1) printf(" ");
                 else printf("\n");
             }
         }
     }
     return 0;
}
