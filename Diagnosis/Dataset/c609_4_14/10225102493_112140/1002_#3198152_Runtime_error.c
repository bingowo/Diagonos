#include <stdio.h>
#include <stdlib.h>

int main()
{
   int T;int n=0;int i=0;
   int a[100];
   while(scanf("%d",T)!=-1)
   {
       printf("case #%d:\n",n);
       int m=T;
       while(m>0){
        a[i]=m%2;
        m=T/2;
        i++;
       }
       int con=0,tcon=0;
       for (i=i-1;i>0;i--){
        if(a[i]!=a[i-1]){
            con++;
        }
        else {
            tcon=con;
            con=0;
        }

       }
       printf("%d",tcon);
       n++;
   }

   return 0;
}

