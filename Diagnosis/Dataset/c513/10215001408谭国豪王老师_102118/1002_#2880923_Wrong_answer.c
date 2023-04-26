#include <stdio.h>
#include <math.h>

int main()
{  char a[10][60];
   int n,i,m,t,g,j=0,b[10];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%s",a[i]);
   }
   i=0;
   for(i=0;i<n;i++)
   {
       while(a[i][j])
       {
           j++;
       }
    if(j==1){b[i]=1;}
    if(j==2){b[i]=2;}
    if(j>2){
        for(m=j-1;m>=0;m--)
        if(m==j-2){t=0;}
        else{t=pow(j,m);}
        if(m=j-1){g=1;}
        else{g=j-m-1;}
        b[i]=b[i]+t*g;
    }
   }
   for(i=0;i<n;i++)
   {
       printf("case #0:\n%d",b[i]);
   }
   return 0;

}
