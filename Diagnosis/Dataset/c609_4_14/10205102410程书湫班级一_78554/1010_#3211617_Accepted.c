#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   int N,R;
   scanf("%d%d",&N,&R);
   int k=0;
   char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char a[100];
   do
   {
       int r=N%R;
       if(r<0){
        r=N-(N/R+1)*R;
        a[k++]=table[r];
        N=N/R+1;
       }
       else{
        r=N%R;
        a[k++]=table[r];
        N=N/R;
       }
   }while(N);
   for(int i=k-1;i>=0;i--) printf("%c",a[i]);
    return 0;
}
