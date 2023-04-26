#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int f[25],c[25];
int main()
{  memset(f,0,25);
   int a,n,m,x;
   scanf("%d %d %d %d",&a,&n,&m,&x);
   f[1]=a;f[2]=a;c[1]=a;
   int b=0;
   while(b<999)
   {
       c[2]=b;
       for(int i=3;i<=n;i++)
       {
           c[i]=c[i-1]+c[i-2];
           f[i]=f[i-1]+c[i-2];
       }
       if(f[n-1]==m)
        break;
       else
        b++;
   }
   printf("%d",f[x]);
   return 0;
}
