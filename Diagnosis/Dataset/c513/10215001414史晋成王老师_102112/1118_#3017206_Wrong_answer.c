#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int w,h,d,i,j,n,m,a[500][500];
char c;
scanf("%d %d %d %c\n",&w,&h,&d,&c);
for(i=0;i<h;i++)
  for(j=0;j<w;j++)
   scanf("%d",&a[i][j]);
while(d>=360)
 d-=360;
 n=d/90;
 if((n==1&&c=='R')||(n==3&&c=='L'))
  { for(j=0;j<w;j++)
     { for(i=h-1;i>=0;i--)
         printf("%d ",a[i][j]);
         printf("\n");
     }
      
  }
 else if(n==2)
 { for(i=h-1;i>=0;i--)
    { for(j=w-1;j>=0;j--)
        printf("%d ",a[i][j]);
        printf("\n");
    }
     
 }
 
 else if((n==3&&c=='R')||(n==1&&c=='L'))
 {  for(j=w-1;j>=0;j--)
     { for(i=0;i<h;i++)
         printf("%d ",a[i][j]);
         printf("\n");
     }
     
 }
    
}