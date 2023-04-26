#include<stdio.h>
int mod(int a,int b)
{
   if(a==0) return 0;
   int r=b%a;
   if(r<0)
   {
       r-=a;
       mod(b/a+1,a);
   }
   else
   {
       mod(b/a,a);
   }
   if(r>=10)
   {
       r='A'+r-10;
   }
   else r=r+'0';
   printf("%c",r);
}
int main(void)
{
    int N,R;
    scanf("%d %d",&N,&R);
    mod(N,R);
    printf("%c",N);
    return 0;
}