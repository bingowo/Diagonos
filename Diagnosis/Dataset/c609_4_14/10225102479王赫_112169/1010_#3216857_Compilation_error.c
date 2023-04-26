#include<stdio.h>
#define char c[16]={0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F};
int main()
{
   char c[16];
   c="0123456789ABCDEF";
   int N,R;
   scanf("%d %d",&N,&R);
   char r[100];
   int count=0;
   while(N){
    int i=0
    r[i++]=c[N%R];
    N/=R;
   }
   printf("%s",r);
   return 0;
}