#include<stdio.h>
#define T 10

int main()
{ int i;char s[T][61];
  for(i=0;i<T;i++)
  {char s[i][61];
  scanf("%s",&s);//输入一个字符串
  int digit=0,N=1;char *p=s;
  a[*p]=1;
  while(*++p)
   
  
    
  
  
  



     if (a[*p]==-1)
     { a[*p]=digit; digit=digit?digit+1:2; N++;}
  if (N<2) N=2;  //不可能是一进制
   long long ans=0;
   p=s; while (*p) ans=ans*N+a[*p++];
   printf("%lld\n",ans);
   return 0;


}
