#include<stdio.h>

int main()
{ char s[61];
  scanf("%s",&s);//输入一个字符串
  int a[128],i;  for (i=0;i<128;i++) a[i]=-1;
  int digit=0,N=1; char *p=s;
  a[*p]=1;
  while (*++p)
     if (a[*p]==-1)
     { a[*p]=digit; digit=digit?digit+1:2; N++;}
  if (N<2) N=2;  //不可能是一进制
   long long ans=0;
   p=s; while (*p) ans=ans*N+a[*p++];
   printf("%lld\n",ans);
   return 0;


}
