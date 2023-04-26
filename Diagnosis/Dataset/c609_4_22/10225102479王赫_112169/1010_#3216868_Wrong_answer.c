#include<stdio.h>
int main()
{
   char c[]="0123456789ABCDEF";
   int N,R;
   scanf("%d %d",&N,&R);
   char r[100];
   int count=0;
   while(N){
    int i=0;
    r[i++]=c[N%R];
    N/=R;
   }
   printf("%s",r);
   return 0;
}