#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int T,i,j,n,m,k,l,a[3][3]={0},row,col,b[3][3]={0};
scanf("%d",&T);
for(i=0;i<T;i++)
{  for(row=1;row<=3;row++)
  { for(col=1;col<=3;col++)
      scanf("%d",&a[row][col]);
  }
  for(row=1;row<=3;row++)
  { for(col=1;col<=3;col++)
      b[row][col]=1;
  }
    for(row=1;row<=3;row++)
  { for(col=1;col<=3;col++)
      { for(k=0;k<a[row][col];k++)
         { if(b[row][col]==1) b[row][col]=0;
             else if(b[row][col]==0) b[row][col]=1;
           if(b[row-1][col]==1) b[row-1][col]=0;
             else if(b[row-1][col]==0) b[row-1][col]=1;
           if(b[row][col-1]==1) b[row][col-1]=0;
             else if(b[row][col-1]==0) b[row][col-1]=1;
           if(b[row+1][col]==1) b[row+1][col]=0;
             else if(b[row+1][col]==0) b[row+1][col]=1;
           if(b[row][col+1]==1) b[row][col+1]=0;
             else if(b[row][col+1]==0) b[row][col+1]=1;
         }
          
      }
  }
  printf("case #%d:\n",i);
  for(row=1;row<=3;row++)
  { for(col=1;col<=3;col++)
      printf("%d ",b[row][col]);
      printf("\n");
  }
  
}
}