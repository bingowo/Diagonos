#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int n,m,a[120][120],i,j,k,l,b[8]={0},row,col;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);
  }
  for(row=1;row<m-1;row++)
  {  for(col=1;col<n-1;col++)
     { int thres=a[row][col];
       b[0]=a[row-1][col-1]>=thres?1:0;
       b[1]=a[row-1][col]>=thres?1:0;
       b[2]=a[row-1][col+1]>=thres?1:0;
       b[3]=a[row][col+1]>=thres?1:0;
       b[4]=a[row+1][col+1]>=thres?1:0;
       b[5]=a[row+1][col]>=thres?1:0;
       b[6]=a[row+1][col-1]>=thres?1:0;
       b[7]=a[row][col-1]>=thres?1:0;
       
       int min=255;
         int d;
         for(k=0;k<=7;k++)
          {
              d=0;
              for(i=0;i<8;i++)
               d=d*2+b[(i+k)%8];
               if(d<min) min=d;
          }
          printf("%d ",d);
     }
      printf("\n");
  }
    
}